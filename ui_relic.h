/********************************************************************************
** Form generated from reading UI file 'relic.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RELIC_H
#define UI_RELIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Relic
{
public:

    void setupUi(QWidget *Relic)
    {
        if (Relic->objectName().isEmpty())
            Relic->setObjectName(QString::fromUtf8("Relic"));
        Relic->resize(781, 477);

        retranslateUi(Relic);

        QMetaObject::connectSlotsByName(Relic);
    } // setupUi

    void retranslateUi(QWidget *Relic)
    {
        Relic->setWindowTitle(QCoreApplication::translate("Relic", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Relic: public Ui_Relic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RELIC_H
