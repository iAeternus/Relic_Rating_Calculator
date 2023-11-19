#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QChar>
#include <QDebug>
#include <QMenuBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    relic(Relic())
{
    initUI();
    initLineEdit();
    initRadioButton();
    initComboBox();
    initPushButton();
    initWidget();
    initMenuBar();
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
}

void MainWindow::initUI()
{
    ui->setupUi(this);
    this->setFixedSize(1600, 1000);
    this->setWindowIcon(QIcon(":/res/pm.jpg"));
    this->setWindowTitle("原神圣遗物评分计算器");
}

void MainWindow::initLineEdit()
{
    // 角色输入
    connect(ui->lineEdit_Name, &QLineEdit::returnPressed, [this]() {
        QString name = ui->lineEdit_Name->text();
        toLowerString(name);
        this->relic.setName(name);
        qDebug() << "输入: " << name;
    });

    // 按回车键时自动切换到下一个输入框
    connect(ui->lineEdit_critChance, &QLineEdit::returnPressed, this, [this]() {
        double a = getValidateInput(ui->lineEdit_critChance, 0, 23.3);
        this->relic.updateAttribute(critChance, a);
        qDebug() << "暴击率: " << a;
    });
    connect(ui->lineEdit_critDamage, &QLineEdit::returnPressed, this, [this]() {
        double b = getValidateInput(ui->lineEdit_critDamage, 0, 46.6);
        this->relic.updateAttribute(critDamage, b);
        qDebug() << "暴击伤害: " << b;
    });
    connect(ui->lineEdit_elementalCharging, &QLineEdit::returnPressed, this, [this]() {
        double c = getValidateInput(ui->lineEdit_elementalCharging, 0, 38.9);
        this->relic.updateAttribute(elementalCharging, c);
        qDebug() << "元素充能效率: " << c;
    });
    connect(ui->lineEdit_elementalMastery, &QLineEdit::returnPressed, this, [this]() {
        double d = getValidateInput(ui->lineEdit_elementalMastery, 0, 140);
        this->relic.updateAttribute(elementalMastery, d);
        qDebug() << "元素精通: " << d;
    });
    connect(ui->lineEdit_attackPercentage, &QLineEdit::returnPressed, this, [this]() {
        double e = getValidateInput(ui->lineEdit_attackPercentage, 0, 35);
        this->relic.updateAttribute(attackPercentage, e);
        qDebug() << "大攻击: " << e;
    });
    connect(ui->lineEdit_attack, &QLineEdit::returnPressed, this, [this]() {
        double f = getValidateInput(ui->lineEdit_attack, 0, 117);
        this->relic.updateAttribute(attack, f);
        qDebug() << "小攻击: " << f;
    });
    connect(ui->lineEdit_healthPercentage , &QLineEdit::returnPressed, this, [this]() {
        double g = getValidateInput(ui->lineEdit_healthPercentage, 0, 35);
        this->relic.updateAttribute(healthPercentage, g);
        qDebug() << "大生命: " << g;
    });
    connect(ui->lineEdit_health, &QLineEdit::returnPressed, this, [this]() {
        double h = getValidateInput(ui->lineEdit_health, 0, 1793);
        this->relic.updateAttribute(health, h);
        qDebug() << "小生命: " << h;
    });
    connect(ui->lineEdit_defensePercentage, &QLineEdit::returnPressed, this, [this]() {
        double i = getValidateInput(ui->lineEdit_defensePercentage, 0, 43.7);
        this->relic.updateAttribute(defensePercentage, i);
        qDebug() << "大防御: " << i;
    });
    connect(ui->lineEdit_defense, &QLineEdit::returnPressed, this, [this]() {
        double j = getValidateInput(ui->lineEdit_defense, 0, 139);
        this->relic.updateAttribute(defense, j);
        qDebug() << "小防御: " << j;
    });

    // 接收有效词条查询输入
    connect(ui->initials, &QLineEdit::returnPressed, this, [this]() {
        QString name = ui->initials->text();
        toLowerString(name);
        qDebug() << name;

        if(name == "") return;

        QString result;
        const Relic* weight = this->relic.searchYieldWeights(name);
        if(weight)
        {
            QVector<double> attributes = weight->getAttributes();

            if (attributes[critChance])
                result.append("暴击率\t\t" + QString::number(static_cast<int>(attributes[critChance] * 100)) + "%\n");
            if (attributes[critDamage])
                result.append("暴击伤害\t\t" + QString::number(static_cast<int>(attributes[critDamage] * 100)) + "%\n");
            if (attributes[elementalCharging])
                result.append("元素充能效率\t" + QString::number(static_cast<int>(attributes[elementalCharging] * 100)) + "%\n");
            if (attributes[elementalMastery])
                result.append("元素精通\t\t" + QString::number(static_cast<int>(attributes[elementalMastery] * 100)) + "%\n");
            if (attributes[attackPercentage])
                result.append("攻击力百分比\t" + QString::number(static_cast<int>(attributes[attackPercentage] * 100)) + "%\n");
            if (attributes[attack])
                result.append("攻击力\t\t" + QString::number(static_cast<int>(attributes[attack] * 100)) + "%\n");
            if (attributes[healthPercentage])
                result.append("生命值百分比\t" + QString::number(static_cast<int>(attributes[healthPercentage] * 100)) + "%\n");
            if (attributes[health])
                result.append("生命值\t\t" + QString::number(static_cast<int>(attributes[health] * 100)) + "%\n");
            if (attributes[defensePercentage])
                result.append("防御力百分比\t" + QString::number(static_cast<int>(attributes[defensePercentage] * 100)) + "%\n");
            if (attributes[defense])
                result.append("防御力\t\t" + QString::number(static_cast<int>(attributes[defense] * 100)) + "%\n");
        }
        else
        {
            result.append("该角色不存在！");
        }

        ui->validEntries->setText(result);
        QFont font;
        font.setPointSize(16);
        font.setFamily("微软雅黑");
        ui->validEntries->setFont(font);
    });
}

void MainWindow::initRadioButton()
{
    // 主词条选择
    connect(ui->radioButton, &QRadioButton::clicked, [this]() {
        this->relic.setIsCritical(true);
        qDebug() << "主词条为双爆";
    });
    connect(ui->radioButton_2, &QRadioButton::clicked, [this]() {
        this->relic.setIsCritical(false);
        qDebug() << "主词条不为双爆";
    });
}

void MainWindow::initComboBox()
{
    // 下拉框
    ui->comboBox->addItems(QStringList() << "请选择" << "生之花" << "死之羽" << "时之沙" << "空之杯" << "理之冠");
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, [this]() {
         int selectedIndex = ui->comboBox->currentIndex();
         this->relic.setPosition(selectedIndex);
         qDebug() << "选中: " << selectedIndex;
    });
}

void MainWindow::initPushButton()
{
    connect(ui->calculate, &QPushButton::clicked, [this]() {
        double score = this->relic.calculate();
        qDebug() << "分数为：" << score;

        // 设置 QLabel 的文本、对齐方式、字号和颜色
        ui->result->setText(QString::number(score));
        ui->result->setAlignment(Qt::AlignCenter);
        ui->result->setFont(QFont("Arial", 20)); // 设置字体和字号
        ui->result->setStyleSheet("color: red;"); // 设置文本颜色为红色
    });
}

void MainWindow::initWidget()
{
    ui->bg->setAutoFillBackground(true);
    QImage image;
    QPalette palette;
    image.load(":/res/bg2.jpg");

    // 计算窗口部件的尺寸
    int width = ui->bg->width();
    int height = ui->bg->height();

    // 调整图像大小以适应窗口部件的大小
    image = image.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    palette.setBrush(this->backgroundRole(), QBrush(image));
    ui->bg->setPalette(palette);
}

void MainWindow::initMenuBar()
{
    // 菜单栏
    QMenuBar* bar = menuBar();
    this->setMenuBar(bar);

    QMenu* navigationMenu = bar->addMenu("导航");

    QAction* assistance = navigationMenu->addAction("帮助");
    connect(assistance, &QAction::triggered, this, [this]() {
        QMessageBox* messageBox = new QMessageBox(this);
        messageBox->setText("帮助\n\n"
                            "1.输入该圣遗物所属角色全称的首字母和其副词条即可计算评分，例如：霄宫 -> xg\n(注：优菈、科莱要输全拼)\n\n"
                            "2.在输入框内输入完成后必须按下回车已确认，之后程序会自动跳到下一个输入框\n\n"
                            "3.圣遗物没有的词条可以跳过不输入");
        messageBox->setWindowTitle("帮助");
        messageBox->setIcon(QMessageBox::Information);
        messageBox->setStandardButtons(QMessageBox::Ok);

        QFont font;
        font.setPointSize(10);
        messageBox->setFont(font);

        messageBox->exec();
    });

    QAction* about = navigationMenu->addAction("关于");
    connect(about, &QAction::triggered, this, [this]() {
        QMessageBox* messageBox = new QMessageBox(this);
        messageBox->setText("版本：" + version + "\n"
                            "作者：Ricky");
        messageBox->setWindowTitle("关于");
        messageBox->setIcon(QMessageBox::Information);
        messageBox->setStandardButtons(QMessageBox::Ok);

        QFont font;
        font.setPointSize(10);
        messageBox->setFont(font);

        messageBox->exec();
    });

    navigationMenu->addSeparator();
    QAction* exit = navigationMenu->addAction("退出");
    connect(exit, &QAction::triggered, this, &MainWindow::close);
}

double MainWindow::getValidateInput(QLineEdit* lineEdit, double min, double max)
{
    bool conversionOk;
    double value = lineEdit->text().toDouble(&conversionOk);

    if (conversionOk && value >= min && value <= max)
    {
        // 输入是有效的并在给定范围内
        // 继续使用该值
        lineEdit->setStyleSheet(""); // 清除错误指示

        QMap<QLineEdit*, QLineEdit*> nextLineEditMap;
        nextLineEditMap.insert(ui->lineEdit_critChance, ui->lineEdit_critDamage);
        nextLineEditMap.insert(ui->lineEdit_critDamage, ui->lineEdit_elementalCharging);
        nextLineEditMap.insert(ui->lineEdit_elementalCharging, ui->lineEdit_elementalMastery);
        nextLineEditMap.insert(ui->lineEdit_elementalMastery, ui->lineEdit_attackPercentage);
        nextLineEditMap.insert(ui->lineEdit_attackPercentage, ui->lineEdit_attack);
        nextLineEditMap.insert(ui->lineEdit_attack, ui->lineEdit_healthPercentage);
        nextLineEditMap.insert(ui->lineEdit_healthPercentage, ui->lineEdit_health);
        nextLineEditMap.insert(ui->lineEdit_health, ui->lineEdit_defensePercentage);
        nextLineEditMap.insert(ui->lineEdit_defensePercentage, ui->lineEdit_defense);

        QLineEdit* nextLineEdit = nextLineEditMap.value(lineEdit);
        if (nextLineEdit)
            nextLineEdit->setFocus();

        return value;
    }
    else
    {
        lineEdit->setStyleSheet("border: 2px solid red;");
        return -1;
    }
}

void MainWindow::toLowerString(QString& str)
{
    for(auto& c : str)
    {
        if(c.isUpper())
        {
            c = c.toLower();
        }
    }
}
