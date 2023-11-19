#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

#include "relic.h"

const QString version = "1.2";

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initUI();
    void initLineEdit();
    void initRadioButton();
    void initComboBox();
    void initPushButton();
    void initWidget();
    void initMenuBar();

    double getValidateInput(QLineEdit* lineEdit, double min, double max);

private:
    Ui::MainWindow *ui;
    Relic relic;

    void toLowerString(QString& str);
};

#endif // MAINWINDOW_H
