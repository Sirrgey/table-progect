#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define MAX_MAS_SIZE 200 //макс размер массива
#include <QMessageBox>// подключаем библиотеку с окошками сообщений

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_DelRow_clicked();

    void on_pushButton_AddRow_clicked();

    void on_spinBox_Row_valueChanged(int arg1);

    void on_pushButton_Sum_clicked();

    void on_pushButton_Random_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    void on_pushButton_Min_clicked();

    void on_pushButton_Max_clicked();

    void on_pushButton_Average_clicked();

    //void on_pushButton_Magic_clicked();

    void on_pushButton_Boubble_clicked();

    void on_pushButton_gnom_clicked();

    void on_pushButton_quick_clicked();

    void on_pushButton_monk_clicked();

    void on_pushButton_brush_clicked();

    void on_pushButton_vibor_clicked();


    void on_pushButton_dubli_clicked();





    void on_pushButton_poisk_clicked();

    void on_pushButton_poisk_ots_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool no_auto_change;//признак не автоматического режима
    int mas_table[MAX_MAS_SIZE][MAX_MAS_SIZE];//будет одномерный массив
    bool flagSort = false;
};

#endif // MAINWINDOW_H
