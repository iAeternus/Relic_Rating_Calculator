#include "relic.h"

#include <QFile>
#include <QDebug>

Relic::Relic(const QVector<double>& attributes) :
    name(QString()), isCritical(false), position(0)
{
    this->attributes = attributes;
}

Relic::Relic(const QString &name, bool isCritical, int position) :
    name(name), isCritical(isCritical), position(position)
{
    this->attributes = QVector<double>(10);
    readYieldWeightsFromFile(QString(":/res/YieldWeights.txt"));
}

Relic::Relic(const Relic &other) :
    name(other.name), isCritical(other.isCritical), position(other.position), attributes(other.attributes)
{}

Relic &Relic::operator=(const Relic &other)
{
    if(this != &other)
    {
        this->name = other.name;
        this->isCritical = other.isCritical;
        this->position = other.position;
        this->attributes = other.attributes;
    }
    return *this;
}

Relic::Relic(Relic&& other) noexcept :
    name(other.name), isCritical(other.isCritical), position(other.position), attributes(other.attributes)
{}

Relic& Relic::operator=(Relic&& other) noexcept
{
    if(this != &other)
    {
        this->name = std::move(other.name);
        this->isCritical = other.isCritical;
        this->position = other.position;
        this->attributes = std::move(other.attributes);
    }
    return *this;
}

QVector<double> Relic::getAttributes() const
{
    return this->attributes;
}

QString Relic::getName() const
{
    return this->name;
}

bool Relic::getIsCritical() const
{
    return this->isCritical;
}

int Relic::getPosition() const
{
    return this->position;
}

void Relic::setAttributes(const QVector<double>& attributes)
{
    this->attributes = attributes;
}

void Relic::setName(const QString &name)
{
    this->name = name;
}

void Relic::setIsCritical(bool isCritical)
{
    this->isCritical = isCritical;
}

void Relic::setPosition(int position)
{
    this->position = position;
}

void Relic::setRelic(const QVector<double>& attributes, const QString &name, bool isCritical, int position)
{
    this->name = name;
    this->isCritical = isCritical;
    this->position = position;
    this->attributes = attributes;
}

void Relic::updateAttribute(size_t index, double attribute)
{
    this->attributes[index] = attribute;
}

bool Relic::operator==(const Relic &other)
{
    bool tag = this->name == other.name && this->isCritical == other.isCritical && this->position == other.position;
    for(int i = 0; tag && i < 10; i++)
    {
        if(this->attributes[i] != other.attributes[i])
        {
            tag = false;
        }
    }
    return tag;
}

bool Relic::operator!=(const Relic &other)
{
    return !(*this == other);
}

double Relic::calculate() const
{
    const Relic* yieldWeight = searchYieldWeights(this->name);
    if(!yieldWeight) return 0;

    double score =
        (this->attributes[critChance] * 2.0 * yieldWeight->attributes[critChance]) +
        (this->attributes[critDamage] * 1.0 * yieldWeight->attributes[critDamage]) +
        (this->attributes[elementalCharging] * 1.1979 * yieldWeight->attributes[elementalCharging]) +
        (this->attributes[elementalMastery] * 0.33 * yieldWeight->attributes[elementalMastery]) +
        (this->attributes[attackPercentage] * 1.33 * yieldWeight->attributes[attackPercentage]) +
        (this->attributes[attack] * 0.398  * 0.5 * yieldWeight->attributes[attack]) +
        (this->attributes[healthPercentage] * 1.33 * yieldWeight->attributes[healthPercentage]) +
        (this->attributes[health] * 0.026  * 0.66 * yieldWeight->attributes[health]) +
        (this->attributes[defensePercentage] * 1.06 * yieldWeight->attributes[defensePercentage]) +
        (this->attributes[defense] * 0.355  * 0.66 * yieldWeight->attributes[defense]);

    score += isCritical ? 20 : 0;
    score = (static_cast<int>(score * 100 + 0.5)) / 100.0;
    return score;
}

bool Relic::isValid(double * const attributes, const QString &name, int position) const
{
    return
        attributes[0] <= 23.3 && attributes[0] >= 0 &&
        attributes[1] <= 46.6 && attributes[1] >= 0 &&
        attributes[2] <= 38.9 && attributes[2] >= 0 &&
        attributes[3] <= 140  && attributes[3] >= 0 &&
        attributes[4] <= 35   && attributes[4] >= 0 &&
        attributes[5] <= 117  && attributes[5] >= 0 &&
        attributes[6] <= 35   && attributes[6] >= 0 &&
        attributes[7] <= 1793 && attributes[7] >= 0 &&
        attributes[8] <= 43.7 && attributes[8] >= 0 &&
        attributes[9] <= 139  && attributes[9] >= 0 &&
        Relic::searchYieldWeights(name) &&
        position >= 1 && position <= 5;
}

void Relic::readYieldWeightsFromFile(const QString& filePath)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << filePath << " open failed！";
        return;
    }

    if (file.size() > 0)
    {
        // 读取整个文件内容
        QString content = file.readAll();

        // 按行分割字符串
        QStringList lines = content.split("\n");

        // 遍历每一行
        for (const QString& line : lines)
        {
            // 使用制表符分割字符串
            QStringList attributesSplit = line.split('\t');

            // 获取所属角色
            if(attributesSplit.size() == 11)
            {
                QVector<double> attributes;
                for(int i = 1; i < 11; ++i)
                {
                    attributes.append(attributesSplit[i].toDouble());
                }

                Relic r(attributes);
                r.setName(attributesSplit[0]);
                this->yieldWeights.append(r);
            }
            else
            {
                qDebug() << "Line does not contain 11 elements: " << line;
            }
        }
    }
    else
    {
        qDebug() << "The file is empty.";
    }
}

const Relic* Relic::searchYieldWeights(const QString &name) const
{
    for (int i = 0; i < this->yieldWeights.size(); i++)
    {
        if (this->yieldWeights[i].name == name)
        {
            return &this->yieldWeights[i];
        }
    }

    return nullptr;
}

