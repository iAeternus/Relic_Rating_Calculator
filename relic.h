#ifndef RELIC_H
#define RELIC_H

#include <QString>
#include <QVector>

enum att
{
    critChance,
    critDamage,
    elementalCharging,
    elementalMastery,
    attackPercentage,
    attack,
    healthPercentage,
    health,
    defensePercentage,
    defense
};

// 圣遗物类
class Relic
{
public:
    Relic(const QVector<double>& attributes);
    Relic(const QString& name = "", bool isCritical = false, int position = 0);
    Relic(const Relic& other);
    Relic& operator=(const Relic& other);
    Relic(Relic&& other) noexcept;
    Relic& operator=(Relic&& other) noexcept;

    // getter
    QString getName() const;
    bool getIsCritical() const;
    int getPosition() const;
    QVector<double> getAttributes() const;

    // setter
    void setName(const QString& name);
    void setIsCritical(bool isCritical);
    void setPosition(int position);
    void setAttributes(const QVector<double>& attributes);
    void setRelic(const QVector<double>& attributes, const QString &name, bool isCritical, int position);

    void updateAttribute(size_t index, double attribute);

    bool operator==(const Relic& other);
    bool operator!=(const Relic& other);

    /**
     * @brief calculate 计算评分 (核心算法)
     * @param yieldWeights 收益权重
     * @param name 圣遗物所属角色
     * @return 返回计算的圣遗物评分
     */
    double calculate() const;

    // 判断词条是否合法
    bool isValid(double* const attributes, const QString& name = "", int position = 0) const;
    // 从文件中读取收益权重
    void readYieldWeightsFromFile(const QString& filePath);
    // 根据名字查询收益权重
    const Relic* searchYieldWeights(const QString& name) const;

private:
    QString name;           // 所属角色名 (霄宫 ==> xg (注：优菈、科莱要输全拼))
    bool    isCritical;     // 主词条是否为双爆 (true-双爆 false-非双爆)
    int     position;       // 圣遗物位置 (1-花 2-毛 3-沙 4-杯 5-头)
    /**
     * @brief attributes 圣遗物词条 (包含圣遗物的 10 种属性) 依次为
     * @note 暴击率
     * @note 暴击伤害
     * @note 元素充能效率
     * @note 元素精通
     * @note 攻击力百分比
     * @note 攻击力
     * @note 生命值百分比
     * @note 生命值
     * @note 防御力百分比
     * @note 防御力
     */
    QVector<double> attributes;
    QVector<Relic> yieldWeights; // 收益权重
};

#endif // RELIC_H
