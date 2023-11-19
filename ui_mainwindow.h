/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_12;
    QLineEdit *lineEdit_Name;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *lineEdit_healthPercentage;
    QLineEdit *lineEdit_attack;
    QLabel *label_4;
    QLineEdit *lineEdit_critDamage;
    QLabel *label_9;
    QLabel *label;
    QLineEdit *lineEdit_attackPercentage;
    QLineEdit *lineEdit_elementalCharging;
    QLineEdit *lineEdit_defense;
    QLabel *label_3;
    QLabel *label_11;
    QLabel *label_5;
    QLineEdit *lineEdit_critChance;
    QLineEdit *lineEdit_defensePercentage;
    QLineEdit *lineEdit_health;
    QLabel *label_7;
    QLineEdit *lineEdit_elementalMastery;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *result;
    QPushButton *calculate;
    QWidget *bg;
    QWidget *tab_2;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_14;
    QLineEdit *initials;
    QLabel *validEntries;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1421, 909);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1600, 1000));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab{width:250}\n"
"QTabBar::tab{height:50}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        widget_4 = new QWidget(tab);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(0, 0, 800, 850));
        widget_4->setMinimumSize(QSize(800, 850));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_12 = new QLabel(widget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_2->addWidget(label_12);

        lineEdit_Name = new QLineEdit(widget_3);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));

        horizontalLayout_2->addWidget(lineEdit_Name);


        gridLayout_2->addWidget(widget_3, 0, 0, 1, 1);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_13 = new QLabel(widget_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_3->addWidget(label_13);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        radioButton = new QRadioButton(widget_5);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(widget_5);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout_3->addWidget(radioButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        gridLayout_2->addWidget(widget_5, 1, 0, 1, 1);

        widget = new QWidget(widget_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(comboBox);


        gridLayout_2->addWidget(widget, 2, 0, 1, 1);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setEnabled(true);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMinimumSize(QSize(0, 600));
        widget_2->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        lineEdit_healthPercentage = new QLineEdit(widget_2);
        lineEdit_healthPercentage->setObjectName(QString::fromUtf8("lineEdit_healthPercentage"));

        gridLayout->addWidget(lineEdit_healthPercentage, 6, 1, 1, 1);

        lineEdit_attack = new QLineEdit(widget_2);
        lineEdit_attack->setObjectName(QString::fromUtf8("lineEdit_attack"));

        gridLayout->addWidget(lineEdit_attack, 5, 1, 1, 1);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lineEdit_critDamage = new QLineEdit(widget_2);
        lineEdit_critDamage->setObjectName(QString::fromUtf8("lineEdit_critDamage"));

        gridLayout->addWidget(lineEdit_critDamage, 1, 1, 1, 1);

        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 7, 0, 1, 1);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_attackPercentage = new QLineEdit(widget_2);
        lineEdit_attackPercentage->setObjectName(QString::fromUtf8("lineEdit_attackPercentage"));

        gridLayout->addWidget(lineEdit_attackPercentage, 4, 1, 1, 1);

        lineEdit_elementalCharging = new QLineEdit(widget_2);
        lineEdit_elementalCharging->setObjectName(QString::fromUtf8("lineEdit_elementalCharging"));

        gridLayout->addWidget(lineEdit_elementalCharging, 2, 1, 1, 1);

        lineEdit_defense = new QLineEdit(widget_2);
        lineEdit_defense->setObjectName(QString::fromUtf8("lineEdit_defense"));

        gridLayout->addWidget(lineEdit_defense, 9, 1, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 9, 0, 1, 1);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        lineEdit_critChance = new QLineEdit(widget_2);
        lineEdit_critChance->setObjectName(QString::fromUtf8("lineEdit_critChance"));

        gridLayout->addWidget(lineEdit_critChance, 0, 1, 1, 1);

        lineEdit_defensePercentage = new QLineEdit(widget_2);
        lineEdit_defensePercentage->setObjectName(QString::fromUtf8("lineEdit_defensePercentage"));

        gridLayout->addWidget(lineEdit_defensePercentage, 8, 1, 1, 1);

        lineEdit_health = new QLineEdit(widget_2);
        lineEdit_health->setObjectName(QString::fromUtf8("lineEdit_health"));

        gridLayout->addWidget(lineEdit_health, 7, 1, 1, 1);

        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        lineEdit_elementalMastery = new QLineEdit(widget_2);
        lineEdit_elementalMastery->setObjectName(QString::fromUtf8("lineEdit_elementalMastery"));

        gridLayout->addWidget(lineEdit_elementalMastery, 3, 1, 1, 1);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setEnabled(true);

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 8, 0, 1, 1);


        gridLayout_2->addWidget(widget_2, 3, 0, 1, 1);

        result = new QLabel(tab);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(1130, 550, 291, 201));
        result->setFrameShape(QFrame::WinPanel);
        result->setFrameShadow(QFrame::Sunken);
        calculate = new QPushButton(tab);
        calculate->setObjectName(QString::fromUtf8("calculate"));
        calculate->setGeometry(QRect(820, 640, 281, 111));
        bg = new QWidget(tab);
        bg->setObjectName(QString::fromUtf8("bg"));
        bg->setGeometry(QRect(840, 110, 640, 360));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        widget_7 = new QWidget(tab_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(0, 0, 1000, 800));
        verticalLayout = new QVBoxLayout(widget_7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_6 = new QWidget(widget_7);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_14 = new QLabel(widget_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);
        label_14->setLineWidth(0);
        label_14->setTextFormat(Qt::PlainText);

        horizontalLayout_4->addWidget(label_14);

        initials = new QLineEdit(widget_6);
        initials->setObjectName(QString::fromUtf8("initials"));
        initials->setMinimumSize(QSize(0, 50));

        horizontalLayout_4->addWidget(initials);


        verticalLayout->addWidget(widget_6);

        validEntries = new QLabel(widget_7);
        validEntries->setObjectName(QString::fromUtf8("validEntries"));
        validEntries->setMinimumSize(QSize(0, 500));
        validEntries->setFocusPolicy(Qt::NoFocus);
        validEntries->setContextMenuPolicy(Qt::DefaultContextMenu);
        validEntries->setFrameShape(QFrame::Box);
        validEntries->setFrameShadow(QFrame::Sunken);
        validEntries->setMidLineWidth(-1);

        verticalLayout->addWidget(validEntries);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\345\234\243\351\201\227\347\211\251\346\211\200\345\261\236\350\247\222\350\211\262\357\274\210\350\247\222\350\211\262\345\205\250\347\247\260\351\246\226\345\255\227\346\257\215\357\274\211\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\344\270\273\350\257\215\346\235\241\346\230\257\345\220\246\344\270\272\345\217\214\347\210\206\357\274\232", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "\346\230\257", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "\345\220\246", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\234\243\351\201\227\347\211\251\344\275\215\347\275\256\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\224\273\345\207\273\345\212\233\347\231\276\345\210\206\346\257\224\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\205\203\347\264\240\345\205\205\350\203\275\346\225\210\347\216\207\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\347\224\237\345\221\275\345\200\274\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\232\264\345\207\273\347\216\207\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\232\264\345\207\273\344\274\244\345\256\263\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\351\230\262\345\276\241\345\212\233\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\205\203\347\264\240\347\262\276\351\200\232\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\224\273\345\207\273\345\212\233\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\347\224\237\345\221\275\345\200\274\347\231\276\345\210\206\346\257\224\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\351\230\262\345\276\241\345\212\233\347\231\276\345\210\206\346\257\224\357\274\232", nullptr));
        result->setText(QCoreApplication::translate("MainWindow", "\345\234\243\351\201\227\347\211\251\350\257\204\345\210\206\357\274\232", nullptr));
        calculate->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\350\257\204\345\210\206", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", " \350\276\223\345\205\245\350\247\222\350\211\262\345\205\250\347\247\260\351\246\226\345\255\227\346\257\215\357\274\232", nullptr));
        validEntries->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\346\234\211\346\225\210\350\257\215\346\235\241\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
