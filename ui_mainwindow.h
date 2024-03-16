/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QPushButton *pushButton_AddRow;
    QPushButton *pushButton_DelRow;
    QSpinBox *spinBox_Row;
    QPushButton *pushButton_Sum;
    QLabel *label_Sum;
    QPushButton *pushButton_Random;
    QPushButton *pushButton_Min;
    QPushButton *pushButton_Max;
    QLabel *label_Min;
    QLabel *label_Max;
    QPushButton *pushButton_Average;
    QLabel *label_Average;
    QLabel *label_sort;
    QPushButton *pushButton_Boubble;
    QPushButton *pushButton_monk;
    QPushButton *pushButton_brush;
    QPushButton *pushButton_gnom;
    QPushButton *pushButton_quick;
    QPushButton *pushButton_vibor;
    QPushButton *pushButton_dubli;
    QLabel *label_kolich;
    QLabel *label_nomera;
    QPushButton *pushButton_poisk;
    QLineEdit *lineEdit_znach;
    QTextEdit *textEdit_KOLICH;
    QTextEdit *textEdit_NOMER;
    QLineEdit *lineEdit_zn;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1225, 793);
        QFont font;
        font.setFamily(QString::fromUtf8("Gadugi"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 130, 301, 511));
        tableWidget->setRowCount(2);
        tableWidget->setColumnCount(1);
        pushButton_AddRow = new QPushButton(centralWidget);
        pushButton_AddRow->setObjectName(QString::fromUtf8("pushButton_AddRow"));
        pushButton_AddRow->setGeometry(QRect(640, 30, 191, 51));
        pushButton_DelRow = new QPushButton(centralWidget);
        pushButton_DelRow->setObjectName(QString::fromUtf8("pushButton_DelRow"));
        pushButton_DelRow->setGeometry(QRect(850, 30, 181, 51));
        spinBox_Row = new QSpinBox(centralWidget);
        spinBox_Row->setObjectName(QString::fromUtf8("spinBox_Row"));
        spinBox_Row->setGeometry(QRect(1050, 30, 111, 51));
        spinBox_Row->setMinimum(1);
        spinBox_Row->setMaximum(20);
        spinBox_Row->setValue(2);
        pushButton_Sum = new QPushButton(centralWidget);
        pushButton_Sum->setObjectName(QString::fromUtf8("pushButton_Sum"));
        pushButton_Sum->setGeometry(QRect(640, 250, 131, 51));
        label_Sum = new QLabel(centralWidget);
        label_Sum->setObjectName(QString::fromUtf8("label_Sum"));
        label_Sum->setGeometry(QRect(780, 250, 121, 51));
        pushButton_Random = new QPushButton(centralWidget);
        pushButton_Random->setObjectName(QString::fromUtf8("pushButton_Random"));
        pushButton_Random->setGeometry(QRect(640, 160, 411, 51));
        pushButton_Min = new QPushButton(centralWidget);
        pushButton_Min->setObjectName(QString::fromUtf8("pushButton_Min"));
        pushButton_Min->setGeometry(QRect(920, 250, 131, 51));
        pushButton_Max = new QPushButton(centralWidget);
        pushButton_Max->setObjectName(QString::fromUtf8("pushButton_Max"));
        pushButton_Max->setGeometry(QRect(920, 340, 131, 51));
        label_Min = new QLabel(centralWidget);
        label_Min->setObjectName(QString::fromUtf8("label_Min"));
        label_Min->setGeometry(QRect(1060, 250, 121, 51));
        label_Max = new QLabel(centralWidget);
        label_Max->setObjectName(QString::fromUtf8("label_Max"));
        label_Max->setGeometry(QRect(1060, 330, 121, 51));
        pushButton_Average = new QPushButton(centralWidget);
        pushButton_Average->setObjectName(QString::fromUtf8("pushButton_Average"));
        pushButton_Average->setGeometry(QRect(640, 340, 131, 51));
        label_Average = new QLabel(centralWidget);
        label_Average->setObjectName(QString::fromUtf8("label_Average"));
        label_Average->setGeometry(QRect(780, 340, 91, 51));
        label_sort = new QLabel(centralWidget);
        label_sort->setObjectName(QString::fromUtf8("label_sort"));
        label_sort->setGeometry(QRect(400, 40, 171, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_sort->setFont(font1);
        pushButton_Boubble = new QPushButton(centralWidget);
        pushButton_Boubble->setObjectName(QString::fromUtf8("pushButton_Boubble"));
        pushButton_Boubble->setGeometry(QRect(400, 90, 131, 51));
        pushButton_monk = new QPushButton(centralWidget);
        pushButton_monk->setObjectName(QString::fromUtf8("pushButton_monk"));
        pushButton_monk->setGeometry(QRect(400, 150, 131, 51));
        pushButton_brush = new QPushButton(centralWidget);
        pushButton_brush->setObjectName(QString::fromUtf8("pushButton_brush"));
        pushButton_brush->setGeometry(QRect(400, 210, 131, 51));
        pushButton_gnom = new QPushButton(centralWidget);
        pushButton_gnom->setObjectName(QString::fromUtf8("pushButton_gnom"));
        pushButton_gnom->setGeometry(QRect(400, 270, 131, 51));
        pushButton_quick = new QPushButton(centralWidget);
        pushButton_quick->setObjectName(QString::fromUtf8("pushButton_quick"));
        pushButton_quick->setGeometry(QRect(400, 330, 131, 51));
        pushButton_vibor = new QPushButton(centralWidget);
        pushButton_vibor->setObjectName(QString::fromUtf8("pushButton_vibor"));
        pushButton_vibor->setGeometry(QRect(400, 390, 131, 51));
        pushButton_dubli = new QPushButton(centralWidget);
        pushButton_dubli->setObjectName(QString::fromUtf8("pushButton_dubli"));
        pushButton_dubli->setGeometry(QRect(640, 430, 411, 51));
        label_kolich = new QLabel(centralWidget);
        label_kolich->setObjectName(QString::fromUtf8("label_kolich"));
        label_kolich->setGeometry(QRect(640, 590, 151, 41));
        label_nomera = new QLabel(centralWidget);
        label_nomera->setObjectName(QString::fromUtf8("label_nomera"));
        label_nomera->setGeometry(QRect(640, 650, 151, 41));
        pushButton_poisk = new QPushButton(centralWidget);
        pushButton_poisk->setObjectName(QString::fromUtf8("pushButton_poisk"));
        pushButton_poisk->setGeometry(QRect(640, 520, 161, 51));
        lineEdit_znach = new QLineEdit(centralWidget);
        lineEdit_znach->setObjectName(QString::fromUtf8("lineEdit_znach"));
        lineEdit_znach->setGeometry(QRect(830, 520, 121, 51));
        textEdit_KOLICH = new QTextEdit(centralWidget);
        textEdit_KOLICH->setObjectName(QString::fromUtf8("textEdit_KOLICH"));
        textEdit_KOLICH->setGeometry(QRect(830, 590, 121, 41));
        textEdit_NOMER = new QTextEdit(centralWidget);
        textEdit_NOMER->setObjectName(QString::fromUtf8("textEdit_NOMER"));
        textEdit_NOMER->setGeometry(QRect(830, 650, 121, 41));
        lineEdit_zn = new QLineEdit(centralWidget);
        lineEdit_zn->setObjectName(QString::fromUtf8("lineEdit_zn"));
        lineEdit_zn->setGeometry(QRect(40, 50, 111, 51));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 50, 161, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1225, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_AddRow->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        pushButton_DelRow->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        pushButton_Sum->setText(QApplication::translate("MainWindow", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        label_Sum->setText(QString());
        pushButton_Random->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\275\320\264\320\276\320\274 ", nullptr));
        pushButton_Min->setText(QApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\321\203\320\274", nullptr));
        pushButton_Max->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274", nullptr));
        label_Min->setText(QString());
        label_Max->setText(QString());
        pushButton_Average->setText(QApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265", nullptr));
        label_Average->setText(QString());
        label_sort->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\270", nullptr));
        pushButton_Boubble->setText(QApplication::translate("MainWindow", "\320\237\321\203\320\267\321\213\321\200\321\221\320\272", nullptr));
        pushButton_monk->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\265\320\267\321\214\321\217\320\275\320\272\320\260", nullptr));
        pushButton_brush->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\321\221\321\201\320\272\320\260", nullptr));
        pushButton_gnom->setText(QApplication::translate("MainWindow", "\320\223\320\275\320\276\320\274", nullptr));
        pushButton_quick->setText(QApplication::translate("MainWindow", "\320\221\321\213\321\201\321\202\321\200\320\260\321\217", nullptr));
        pushButton_vibor->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200", nullptr));
        pushButton_dubli->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\264\321\203\320\261\320\273\320\270\320\272\320\260\321\202\320\276\320\262", nullptr));
        label_kolich->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_nomera->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200\320\260 \321\201\321\202\321\200\320\276\320\272", nullptr));
        pushButton_poisk->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
