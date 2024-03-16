#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <set>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    no_auto_change = true;
    ui->spinBox_Row->setMaximum(MAX_MAS_SIZE);
    ui->textEdit_KOLICH->setReadOnly(true);
    ui->textEdit_NOMER->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_DelRow_clicked()//удаляем строку
{
    //int row = ui-> tableWidget->rowCount();
    // if (row > 2)
    //     ui->tableWidget->setRowCount(row-1);
    ui->spinBox_Row->setValue(ui->spinBox_Row->value()-1);
    ui->label_Sum->clear();
    ui->label_Max->clear();
    ui->label_Min->clear();
    ui->label_Average->clear();
    ui->textEdit_KOLICH->clear();
    ui->textEdit_NOMER->clear();
}

void MainWindow::on_pushButton_AddRow_clicked()//добавляем строку
{
    //ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    ui->spinBox_Row->setValue(ui->spinBox_Row->value()+1);
    ui->label_Sum->clear();
    ui->label_Max->clear();
    ui->label_Min->clear();
    ui->label_Average->clear();
    ui->textEdit_KOLICH->clear();
    ui->textEdit_NOMER->clear();
}
void raschessort(int size, int sort[])//сортировка расчёской
{
    int n = 0; //
    double fakt = 1.2473309;// оптимальное число для вычисления шага сравнения
    int step = size - 1;

    while (step >= 1)
    {
        for (int i = 0; i + step < size; ++i)
        {
            if (sort[i] > sort[i + step])
            {
                std::swap(sort[i], sort[i + step]);
                n++;
            }
        }
        step /= fakt;
    }
    //
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (sort[j] > sort[j + 1])
            {
                std::swap(sort[j], sort[j + 1]);
                swapped = true;
                ++n;
            }
        }

        if (!swapped)
            break;
    }
    //return n;
}
void bubbleSort(int *num,int size)//сортировка пузырьком
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                //
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int mas[], int len)//сортировка выбором
{
    int j = 0;
    int tmp = 0;
    for(int i=0; i<len; i++){
        j = i;
        for(int k = i; k<len; k++){
            if(mas[j]>mas[k]){
                j = k;
            }
        }
        tmp = mas[i];
        mas[i] = mas[j];
        mas[j] = tmp;
    }
}
void gnomesort(int n, int ar[])//гномбя сортировка
{
    int i=0;
    int j=0;
    int vrem=0;
    while(i<n)
    {
        if((i==0)or(ar[i-1]<=ar[i]))
            i=i+1;
        else
        {
            j=i-1;
            vrem=ar[i];
            ar[i]=ar[j];
            ar[j]=vrem;
            i=i-1;
        }

    }


}
int correct(int *arr, int size)//
{
    while (--size > 0)
    {
        if (arr[size - 1] > arr[size])
            return 0;
    }
    return 1;
}
void shuffle(int *arr, int size, int &)
{
    for (int i = 0; i < size; ++i)
    {
        std::swap(arr[i], arr[(rand() % size)]);
    }
}
int bogoSort(int *arr, int size)//обезьянья сортировка
{
    int per = 0;
    while (!correct(arr, size)&&per<=10000000)
    {
        shuffle(arr, size, per);
        per++;
    }
    if(per>=10000000)//кол-во перестановок
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void quicksort(int *mass, int first, int last)//быстрая сортировка
{
    int mid, count;
    int f=first, l=last;
    mid=mass[(f+l) / 2];
    do
    {
        while (mass[f]<mid)
            f++;
        while (mass[l]>mid)
            l--;
        if (f<=l)
        {
            count=mass[f];
            mass[f]=mass[l];
            mass[l]=count;
            f++;
            l--;
        }
    }
    while (f<l);
    if (first<l) quicksort(mass, first, l);
    if (f<last) quicksort(mass, f, last);
}

void MainWindow::on_spinBox_Row_valueChanged(int arg1)//изменили спинбокс
{
    ui->tableWidget->setRowCount(arg1);
    ui->label_Sum->clear();
    ui->label_Max->clear();
    ui->label_Min->clear();
    ui->label_Average->clear();
    ui->textEdit_KOLICH->clear();
    ui->textEdit_NOMER->clear();
    flagSort = false;
}

void MainWindow::on_pushButton_Sum_clicked()//cумма
{
    no_auto_change = false;
    int row = ui->tableWidget->rowCount();//смотрим кол-во строк
    int sum = 0,m = 0,k = 0;
    bool flag;
    bool error = false;


    for (int i=0;i<row;i++)
        if (ui->tableWidget->item(i,0)!=nullptr)//проверка на существование ячейки
        {
            sum+=ui->tableWidget->item(i,0)->text().toInt(&flag);//вычисляем сумму всех значений
            if (flag)
            {
                ui->tableWidget->item(i,0)->setBackgroundColor(Qt::white);//красим ячейку в белый
                ui->label_Sum->setNum(sum);//присваиваем значение сумме
            }
            else
            {
                ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);//красим ячейку в красный
                while(k!=1)
                {
                    m = i ;
                    k+=1;
                    ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
                }
                error = true;

            }

        }
        else {//не существует
            QTableWidgetItem *ti;//создали указатель
            ti = new QTableWidgetItem;//выделили память
            ui->tableWidget->setItem(i,0,ti);//поместили ячейку в таблицу
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);//красим ячейку в красный
            while(k!=1)
            {
                m = i ;
                k+=1;
            }
            error = true;
        }
    if (error)
    {
        ui->label_Sum->clear();
        QMessageBox::information(this,"Ошибка","Неверное значение в "+QString::number(m+1)+" строке");
        QString::number(QMessageBox::Ok);

    }
    no_auto_change = true;//признак не автоматического режима
}


void MainWindow::on_pushButton_Random_clicked()//выводим радномные числа
{

    no_auto_change=false;
    flagSort = false;
    int row = ui->tableWidget->rowCount();// получаем кол-во строк
    int val;

    for (int i=0; i<row; i++)//работа с массивом
    {
        if (ui->tableWidget->item(i,0)==nullptr)// проверка на пустую ячейку
        {//расширяет память для задачи значения в ячейке
            QTableWidgetItem * ti;
            ti = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);// установка пустого значения в ячейку
        }
        ui->tableWidget->item(i,0)->setBackground(Qt::white);
        val=rand()%201-100;//заполняет ячейки рандомными значениями от -100 до 100
        ui->tableWidget->item(i,0)->setText(QString::number(val));
    }

    //вычисление всех значений
    no_auto_change=true;
}


void MainWindow::on_tableWidget_cellChanged(int row, int column)//изменили ячейку
{   if (no_auto_change)
    {

        bool flag;
        ui->tableWidget->item(row,column)->text().toInt(&flag);//присваиваем значение
        ui->label_Sum->clear();
        ui->label_Max->clear();
        ui->label_Min->clear();
        ui->label_Average->clear();
        ui->textEdit_KOLICH->clear();
        ui->textEdit_NOMER->clear();
        flagSort = false;
        if (flag)
            ui->tableWidget->item(row,column)->setBackgroundColor(Qt::white);//красим в белый
        else
            ui->tableWidget->item(row,column)->setBackgroundColor(Qt::red);//красим в красный
    }

}


void MainWindow::on_pushButton_Min_clicked()//находим минимальное число в таблице
{
    no_auto_change = false;
    ui->label_Min->clear();
    int row = ui -> tableWidget->rowCount();//смотрим кол-во строк
    int Min = 0,k = 0,m = 0;
    bool error = false;

    QTableWidgetItem *item = ui->tableWidget->item(0, 0);
    if(item == nullptr) // проверка на пустоту ячейки
    {
        // если элемент пустой
        item = new QTableWidgetItem();
        ui->tableWidget->setItem(0, 0, item); // установка пустого значения в ячейку
        ui->tableWidget->item(0,0)->setBackgroundColor(Qt::red);// красим в красный
        error = true;
    }

    //проверка на значение
    bool flag = false;
    int value = item->text().toInt(&flag);
    if(!flag)
    {
        ui->tableWidget->item(0,0)->setBackgroundColor(Qt::red);
        error = true;
    }
    else
    {
        Min = value;
    }
    ui->label_Min->setNum(Min);

    if(error)
    {
        ui->label_Min->clear();

    }
    //QMessageBox::information(this,"Ошибка","Неверное значение в ячейке");
    // QString::number(QMessageBox::Ok);

    for (int i=1; i<row; i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i, 0);
        if(item == nullptr) // проверка на пустоту ячейки
        {//не существует
            //создаём
            item = new QTableWidgetItem();
            ui->tableWidget->setItem(i, 0, item); // установка пустого значения в ячейку
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);// красим в красный
            while(k!=1)
            {
                m = i ;
                k+=1;
            }
            error = true;
        }
        else
        {
            //проверка на значение
            bool flag = false;
            int value = item->text().toInt(&flag);
            if(!flag)
            {
                ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);// красим в красный
                while(k!=1)
                {
                    m = i ;
                    k+=1;
                    ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
                }
                error = true;
            }
            if(value < Min)// сравниваем значения
            {
                Min = value;

            }
            ui->label_Min->setNum(Min);
        }
    }
    no_auto_change = true;
    if(error)
    {
        ui->label_Min->clear();
        QMessageBox::information(this,"Ошибка","Неверное значение в "+QString::number(m+1)+" строке");
        QString::number(QMessageBox::Ok);
    }
}



void MainWindow::on_pushButton_Average_clicked()//находим среднее значение всех чисел
{
    no_auto_change = false;
    int row = ui -> tableWidget->rowCount();//смотрим кол-во строк
    double Sred;
    bool flag;
    int m = 0,k = 0;
    bool error = false;
    double sum = 0;


    for (int i=0;i<row;i++)
        if (ui->tableWidget->item(i,0)!=nullptr)//проверка на существование ячейки
        {//существует
            sum += ui->tableWidget->item(i,0)->text().toInt(&flag);//находим сумму
            if (flag)
            {
                ui->tableWidget->item(i,0)->setBackgroundColor(Qt::white);//красим в белый
                Sred = sum / row;//находим ср значение
                ui->label_Average->setNum(Sred);//присваиваем значение ср значения
            }
            else
            {
                ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);//красим в красный
                while(k!=1)
                {
                    m = i ;
                    k+=1;
                    ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
                }
                error = true;
            }

        }
        else {//не существует
            //создаём
            QTableWidgetItem *ti;//создали указатель
            ti = new QTableWidgetItem;//выделили память
            ui->tableWidget->setItem(i,0,ti);//поместили ячейку в таблицу
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);//красим в красный
            while(k!=1)
            {
                m = i ;
                k+=1;
            }
            error = true;
        }
    if (error)
    {
        ui->label_Average->clear();
        QMessageBox::information(this,"Ошибка","Неверное значение в "+QString::number(m+1)+" строке");
        QString::number(QMessageBox::Ok);
    }
    no_auto_change = true;
}

void MainWindow::on_pushButton_Max_clicked()//находим максимальное число в таблице
{
    no_auto_change = false;
    ui->label_Max->clear();
    int row = ui -> tableWidget->rowCount();//смотрим кол-во строк
    int Max = 0,m = 0,k = 0;
    bool error = false;

    QTableWidgetItem *item = ui->tableWidget->item(0, 0);
    if(item == nullptr) // проверка на существование ячейки
    {
        // если элемент пустой
        item = new QTableWidgetItem();
        ui->tableWidget->setItem(0, 0, item); // установка пустого значения в ячейку
        ui->tableWidget->item(0,0)->setBackgroundColor(Qt::red);// красим в красный
        error = true;
    }

    //проверка на значение
    bool flag = false;
    int value = item->text().toInt(&flag);
    if(!flag)
    {
        ui->tableWidget->item(0,0)->setBackgroundColor(Qt::red);// красим в красный
        error = true;
    }
    else
    {
        Max = value;
    }
    ui->label_Max->setNum(Max);

    if(error)
        ui->label_Max->clear();

    for (int i=1; i<row; i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i, 0);
        if(item == nullptr) // проверка на существование ячейки
        {//не существует
            //создаём
            item = new QTableWidgetItem();
            ui->tableWidget->setItem(i, 0, item); // установка пустого значения в ячейку
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);// красим в красный
            while(k!=1)
            {
                m = i ;
                k+=1;

            }
            error = true;
        }
        else
        {
            //проверка на значение
            bool flag = false;
            int value = item->text().toInt(&flag);
            if(!flag)
            {
                ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);// красим в красный
                while(k!=1)
                {
                    m = i ;
                    k+=1;
                    ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
                }
                error = true;
            }
            if(value > Max)// сравниваем значения
            {
                Max = value;

            }
            ui->label_Max->setNum(Max);
        }
    }
    no_auto_change = true;
    if(error)
    {
        ui->label_Max->clear();
        QMessageBox::information(this,"Ошибка","Неверное значение в "+QString::number(m+1)+" строке");
        QString::number(QMessageBox::Ok);
    }
}
void MainWindow::on_pushButton_Boubble_clicked()//функция сортировки пузырьком
{

    no_auto_change = false;
    ui->textEdit_NOMER->clear();
    int mas_size=ui->tableWidget->rowCount();
    int *mas = new int[mas_size];
    int m = 0,k = 0;
    bool gl_flag;//признак правильного перенесения значений из таблицы в массив
    bool loc_flag;//признак успешного перенесения ячейки
    gl_flag = true;
    for(int i = 0;i<mas_size;i++)
    {
        if (ui->tableWidget->item(i,0)!=nullptr)//проверяем ячейку на существование
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&loc_flag);
        }
        else//создаём ячейку
        {
            loc_flag = false;
            QTableWidgetItem *ti;
            ti = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);
            while(k!=1)
            {
                m = i ;
                k+=1;
            }
        }
        if (loc_flag)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else {
            gl_flag = false;
            ui->tableWidget->item(i,0)->setBackground(Qt::red);
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            while(k!=1)
            {
                m = i ;
                k+=1;
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            }
        }

    }
    if (gl_flag)//если всё верно используем функцию для вычислений
    {
        //        while(i<(mas_size-1))
        //            j = i + 1;
        //        while(j<mas_size){
        //            if (mas[i]<mas[j]){
        //                buf = mas[i];
        //                mas[i] = mas[j];
        //                mas[j] = buf;
        //            }
        //            j++;
        //        }
        //        i++;
        bubbleSort(mas,mas_size);
        for(int i=0; i<mas_size;i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(mas[i])));

        }
        flagSort = true;
    }
    else
    {

        QMessageBox::information(this,"Ошибка","Неверное значение в "+QString::number(m+1)+" строке");
        QString::number(QMessageBox::Ok);

    }
    delete [] mas;
    no_auto_change = true;

}




void MainWindow::on_pushButton_gnom_clicked()//функция гномьей сортировки
{
    no_auto_change = false;
    ui->textEdit_NOMER->clear();

    int mas_size=ui->tableWidget->rowCount();
    int *mas = new int[mas_size];
    int k = 0,m = 0;
    bool gl_flag;//признак правильного перенесения значений из таблицы в массив
    bool loc_flag;//признак успешного перенесения ячейки

    gl_flag = true;
    for(int i = 0;i<mas_size;i++)
    {
        if (ui->tableWidget->item(i,0)!=nullptr)//проверяем ячейку на существование
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&loc_flag);
        }
        else//создаём ячейку
        {
            loc_flag = false;
            QTableWidgetItem *ti;
            ti = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            while(k!=1)
            {
                m = i ;
                k+=1;
            }
        }
        if (loc_flag)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else {
            gl_flag = false;
            ui->tableWidget->item(i,0)->setBackground(Qt::red);
            while(k!=1)
            {
                m = i ;
                k+=1;
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            }
        }

    }

    if (gl_flag)//если всё верно используем функцию для вычислений
    {
        gnomesort(mas_size,mas);
        for(int i=0; i<mas_size;i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(mas[i])));
        }
    }
    else
    {
        QMessageBox::information(this,"Ошибка","Неверное значение в "+QString::number(m+1)+" строке");
        QString::number(QMessageBox::Ok);
    }
    flagSort = true;
    delete [] mas;
    no_auto_change = true;
}

void MainWindow::on_pushButton_quick_clicked()//функция быстрой сортировки
{

    no_auto_change = false;
    ui->textEdit_NOMER->clear();
    int k = 0,m = 0;
    int mas_size=ui->tableWidget->rowCount();
    int *mas = new int[mas_size];

    bool gl_flag;//признак правильного перенесения значений из таблицы в массив
    bool loc_flag;//признак успешного перенесения ячейки

    gl_flag = true;
    for(int i = 0;i<mas_size;i++)
    {
        if (ui->tableWidget->item(i,0)!=nullptr)//проверяем ячейку на существование
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&loc_flag);
        }
        else//создаём ячейку
        {
            loc_flag = false;
            QTableWidgetItem *ti;
            ti = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            while(k!=1)
            {
                m = i ;
                k+=1;
            }
        }
        if (loc_flag)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else {
            gl_flag = false;
            ui->tableWidget->item(i,0)->setBackground(Qt::red);
            while(k!=1)
            {
                m = i ;
                k+=1;
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            }
        }

    }

    if (gl_flag)//если всё верно используем функцию для вычислений
    {

        quicksort(mas,0,mas_size-1);
        for(int i=0; i<mas_size;i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(mas[i])));
        }
    }
    else
    {
        QMessageBox::information(this,"Ошибка","Неверное значение в "+QString::number(m+1)+" строке");
        QString::number(QMessageBox::Ok);
    }
    flagSort = true;
    delete [] mas;
    no_auto_change = true;
}



void MainWindow::on_pushButton_monk_clicked()//функция обезьяньей сортировки
{

    no_auto_change = false;
    ui->textEdit_NOMER->clear();
    int m = 0,k = 0;
    int mas_size=ui->tableWidget->rowCount();
    int *mas = new int[mas_size];

    bool gl_flag;//признак правильного перенесения значений из таблицы в массив
    bool loc_flag;//признак успешного перенесения ячейки

    gl_flag = true;
    for(int i = 0;i<mas_size;i++)
    {
        if (ui->tableWidget->item(i,0)!=nullptr)//проверяем ячейку на существование
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&loc_flag);
        }
        else//создаём ячейку
        {
            loc_flag = false;
            QTableWidgetItem *ti;
            ti = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);
            while(k!=1)
            {
                m = i ;
                k+=1;
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            }
        }
        if (loc_flag)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else {
            gl_flag = false;
            ui->tableWidget->item(i,0)->setBackground(Qt::red);
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            while(k!=1)
            {
                m = i ;
                k+=1;
            }
        }

    }

    if (gl_flag)
    {

        int m=bogoSort(mas,mas_size);
        if(m==1)
        {
            QMessageBox::information(this, "Ошибка", "Функция слишком долго выполнялась",QMessageBox::Ok);
            return;
        }
        else
        {
            for(int i=0; i<mas_size;i++)
            {
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(mas[i])));
            }
        }
    }
    else
    {
        QMessageBox::information(this,"Ошибка","Неверное значение в "+QString::number(m+1)+" строке");
        QString::number(QMessageBox::Ok);
    }
    flagSort = true;
    delete [] mas;
    no_auto_change = true;
}


void MainWindow::on_pushButton_brush_clicked()//функция сортировки расчёской
{

    no_auto_change = false;
    ui->textEdit_NOMER->clear();
    int m = 0,k = 0;
    int mas_size=ui->tableWidget->rowCount();
    int *mas = new int[mas_size];

    bool gl_flag;//признак правильного перенесения значений из таблицы в массив
    bool loc_flag;//признак успешного перенесения ячейки
    //формируем массив
    gl_flag = true;
    for(int i = 0;i<mas_size;i++)
    {
        if (ui->tableWidget->item(i,0)!=nullptr)//проверяем ячейку на существование
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&loc_flag);
        }
        else//слздаём ячейку
        {
            loc_flag = false;
            QTableWidgetItem *ti;
            ti = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);
            while(k!=1)
            {
                m = i ;
                k+=1;
            }
        }
        if (loc_flag)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else {
            gl_flag = false;
            ui->tableWidget->item(i,0)->setBackground(Qt::red);
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            while(k!=1)
            {
                m = i ;
                k+=1;
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            }
        }

    }

    if (gl_flag)//если всё верно используем функцию для вычислений
    {
        raschessort(mas_size,mas);//сортировка расчёской
        for(int i=0; i<mas_size;i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(mas[i])));
        }

    }
    else
    {
        QMessageBox::information(this,"Ошибка","Неверное значение в "+QString::number(m+1)+" строке");
        QString::number(QMessageBox::Ok);
    }
    flagSort = true;
    delete [] mas;
    no_auto_change = true;
}

void MainWindow::on_pushButton_vibor_clicked()//функция сортировки выбором
{

    no_auto_change = false;
    int m = 0,k = 0;

    int mas_size=ui->tableWidget->rowCount();
    int *mas = new int[mas_size];
    bool gl_flag;//признак правильного перенесения значений из таблицы в массив
    bool loc_flag;//признак успешного перенесения ячейки

    gl_flag = true;
    for(int i = 0;i<mas_size;i++)
    {
        if (ui->tableWidget->item(i,0)!=nullptr)//проверяем ячейку на существование
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&loc_flag);
        }
        else//создаём ячейку
        {
            loc_flag = false;
            QTableWidgetItem *ti;
            ti = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);
            while(k!=1)
            {
                m = i ;
                k+=1;
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            }
        }
        if (loc_flag)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else {
            gl_flag = false;
            ui->tableWidget->item(i,0)->setBackground(Qt::red);
            while(k!=1)
            {
                m = i ;
                k+=1;
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            }
        }

    }

    if (gl_flag)
    {

        selectionSort(mas,mas_size);
        for(int i=0; i<mas_size;i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(mas[i])));
        }
    }
    else
    {
        QMessageBox::information(this,"Ошибка","Неверное значение в "+QString::number(m+1)+" строке");
        QString::number(QMessageBox::Ok);
    }
    flagSort = true;
    delete [] mas;
    no_auto_change = true;
}



void MainWindow::on_pushButton_dubli_clicked()//функция для удаления дубликатов
{

    no_auto_change = false;
    bool gl_flag = true;
    bool loc_flag;
    bool sort = true;
    int mas_size=ui->tableWidget->rowCount();
    int *mass = new int[mas_size];
    int m = 0,k = 0;
    for(int i=0; i<mas_size; i++)
    {
        if (ui->tableWidget->item(i,0)!=nullptr)//проверяем на существоване
        {
            mass[i]=ui->tableWidget->item(i,0)->text().toInt(&loc_flag);

        }
        else
        {
            loc_flag = true;
            QTableWidgetItem *ti;
            ti = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);
            while(k!=1)
            {
                m = i ;
                k+=1;
            }

        }

        if ((i>0) && (ui->tableWidget->item(i-1,0)->text().toInt()>ui->tableWidget->item(i,0)->text().toInt()))
            sort = false;

        if (loc_flag)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else
        {
            gl_flag = false;
            ui->tableWidget->item(i,0)->setBackground(Qt::red);
            while(k!=1)
            {
                m = i ;
                k+=1;
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            }
        }
    }
    if (sort)
    {
      if (gl_flag)
      {
        int l=0;
        int mass2[MAX_MAS_SIZE];
        mass2[0]=mass[0];
        for (int i=1; i<=mas_size-1; i++)
        {
            if (mass[i-1]!=mass[i])//записываем в массив 2 уникальные элем
            {
                l++;
                mass2[l]=mass[i];
            }
        }
        mas_size=l+1;
        ui->spinBox_Row->setValue(mas_size);
        ui->tableWidget->setRowCount(mas_size);//создаём нужное кол-во строчек
        for (int i=0; i<=mas_size-1 ;i++)//
        {
            ui->tableWidget->item(i, 0)->setText(QString::number(mass2[i]));
        }

       }
       else
       {
        QMessageBox::information(this,"Ошибка","Неверное значение в "+QString::number(m+1)+" строке");
        QString::number(QMessageBox::Ok);
       }
    }
    else
    {
        QMessageBox::information(this,"Ошибка","Таблица не отсортирована!");
        QString::number(QMessageBox::Ok);
    }
    delete [] mass;
    flagSort = true;
    no_auto_change = true;

}


void MainWindow::on_pushButton_poisk_clicked()//функция поиска
{
   ui->textEdit_KOLICH->setReadOnly(true);
   ui->textEdit_NOMER->setReadOnly(true);
   int m = 0,k = 0;
   bool loc_flag;
   bool gl_flag = true;
   int mas_size = ui->spinBox_Row->value();
   int mass[MAX_MAS_SIZE];
   for(int i = 0;i<mas_size;i++)
   {
       if (ui->tableWidget->item(i,0)!=nullptr)
       {
           mass[i] = ui->tableWidget->item(i,0)->text().toInt(&loc_flag);
       }
       else //создаём ячейку
       {
            loc_flag = false;
            QTableWidgetItem * ti;
            ti = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);
            while(k!=1)
            {
                m = i ;
                k+=1;
            }
       }
       if (loc_flag)
       {
           ui->tableWidget->item(i,0)->setBackgroundColor(Qt::white);
       }
       else
        {
          ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
          gl_flag = false;
          while(k!=1)
          {
              m = i ;
              k+=1;
              ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
          }
        }

   }
   bool flag;
   if (gl_flag)
   {
       int znach = ui->lineEdit_znach->text().toInt(&flag);
       QString nomer;
       int kolich = 0;
       int d = 0;
       k = 0;
       if (flag)
       {
           if (flagSort)
           {

               for(int i=0; i<mas_size; i++)
               {
                   int middle_index=0; // переменная для хранения индекса среднего элемента массива
                   int first_index=0; // индекс первого элемента в массиве
                   int last_index=mas_size - 1; // индекс последнего элемента в массиве
                   int search_index=znach; // искомое (ключевое) значение

                   while (first_index<last_index)
                   {
                       middle_index=(first_index+last_index)/2; // меняем индекс среднего значения
                       search_index<=mass[middle_index] ? last_index=middle_index:first_index=middle_index+1; // найден ключевой элемент или нет
                   }
                   if(last_index > 1)// Найдя хотя бы один элемент, отматываем назад в поисках первого
                   {
                       while(mass[last_index-1] == search_index)
                       {
                           last_index--;
                       }
                   }

                   if (mass[last_index]==search_index)
                   {

                       for(int i = last_index; mass[i] == search_index; i++)// Проверяем от первого элемента до расхождения
                       {
                           kolich++;
                           nomer += QString::number(i+1)+";";//добавляем значение в стоку
                           ui->tableWidget->item(i,0)->setBackgroundColor(Qt::green);
                       }
                       QString str;
                       str+=QString::number(kolich);
                       ui->textEdit_KOLICH->setText(str);
                       ui->textEdit_NOMER->setText(nomer);
                       break;




                   }
                   else
                   {
                       while (k!=1)
                       {
                        QMessageBox::information(this, "Ошибка!", "Тfкого элемента нет в таблице");
                        QString::number(QMessageBox::Ok);
                        k++;
                       }

                   }


               }

           }
           else
           {

            for (int i = 0;i<mas_size;i++)
            {
               if (znach == mass[i])
               {
                   nomer += QString::number(i+1)+";";//добавляем значение в стоку
                   kolich ++;//считает кол-во чисел

               }
               QString str;
               str+=QString::number(kolich);
               ui->textEdit_KOLICH->setText(str);
               ui->textEdit_NOMER->setText(nomer);


               }
               if (kolich == 0)
               {
                  ui->textEdit_KOLICH->clear();
                  ui->textEdit_NOMER->clear();
                  while(d!=1)
                  {
                     d+=1;
                     QMessageBox::information(this,"Ошибка","Такого значение нет в таблице");
                     QString::number(QMessageBox::Ok);

                   }

              }
          }
       }
       else
       {
           QMessageBox::information(this,"Ошибка","В поиске неверное значение");
           QString::number(QMessageBox::Ok);
           ui->textEdit_KOLICH->clear();
           ui->textEdit_NOMER->clear();
       }
   }
   else
   {
       QMessageBox::information(this,"Ошибка","Неверное значение в "+QString::number(m+1)+" строке");
       QString::number(QMessageBox::Ok);
       ui->textEdit_KOLICH->clear();
       ui->textEdit_NOMER->clear();
   }

}






void MainWindow::on_pushButton_poisk_ots_clicked()
{
//    int m = 0,k = 0;
//    bool loc_flag;
//    bool gl_flag = true;
//    int mas_size = ui->spinBox_Row->value();
//    int mass[MAX_MAS_SIZE];
//    for(int i = 0;i<mas_size;i++)
//    {
//        if (ui->tableWidget->item(i,0)!=nullptr)
//        {
//            mass[i] = ui->tableWidget->item(i,0)->text().toInt(&loc_flag);
//        }
//        else //создаём ячейку
//        {
//             loc_flag = false;
//             QTableWidgetItem * ti;
//             ti = new QTableWidgetItem;
//             ui->tableWidget->setItem(i,0,ti);
//             while(k!=1)
//             {
//                 m = i ;
//                 k+=1;
//             }
//        }
//        if (loc_flag)
//        {
//            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::white);
//        }
//        else
//         {
//           ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
//           gl_flag = false;
//           while(k!=1)
//           {
//               m = i ;
//               k+=1;
//               ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
//           }
//         }

//    }
//    bool flag;
//    if (gl_flag)
//    {
//        int znach = ui->lineEdit_znach->text().toInt(&flag);
//        QString nomer;
//        int kolich = 0;
//        int d = 0;
//        if (flag)
//        {
//            quicksort(mass,0,mas_size-1);
//            for (int i = 0;i<mas_size;i++)
//            {
//                if (znach == mass[i])
//                {
//                    nomer += QString::number(i+1)+";";//добавляем значение в стоку
//                    kolich ++;//считает кол-во чисел

//                }
//                ui->label_KOLICH->setNum(kolich);
//                ui->label_NOMERA->setText(nomer);


//                }
//                if (kolich == 0)
//                {
//                    ui->label_KOLICH->clear();
//                    ui->label_NOMERA->clear();
//                    while(d!=1)
//                    {
//                        d+=1;
//                        QMessageBox::information(this,"Ошибка","Такого значение нет в таблице");
//                        QString::number(QMessageBox::Ok);
//                    }

//            }
//        }
//        else {
//            QMessageBox::information(this,"Ошибка","В поиске неверное значение");
//            QString::number(QMessageBox::Ok);
//            ui->label_KOLICH->clear();
//            ui->label_NOMERA->clear();
//        }
//    }
//    else
//    {
//        QMessageBox::information(this,"Ошибка","Неверное значение в "+QString::number(m+1)+" строке");
//        QString::number(QMessageBox::Ok);
//        ui->label_KOLICH->clear();
//        ui->label_NOMERA->clear();
//    }
}

void MainWindow::on_pushButton_clicked()
{
    no_auto_change = false;

    int row = ui->tableWidget->rowCount();
    bool flag = true;
    int zn = ui->lineEdit_zn->text().toInt(&flag);

    if (flag)
    {
        for (int i = 0; i < row; i++)
        {
            if (ui->tableWidget->item(i, 0) != nullptr) // проверка сущ-я ячейки
            {
                ui->tableWidget->item(i, 0)->setText(QString::number(zn));
                ui->tableWidget->item(i, 0)->setBackgroundColor(Qt::white);

            }
            else // ячейка не существует
            {

                // cоздание
                QTableWidgetItem * ti; // создание указателя
                ti = new QTableWidgetItem; // выделение памяти
                ui->tableWidget->setItem(i, 0, ti); // поместили ячейку в таблицу
                ui->tableWidget->item(i, 0)->setText(QString::number(zn));
                ui->tableWidget->item(i, 0)->setBackgroundColor(Qt::white);

            }
        }
    }
    else
    {
        QMessageBox::information(this,"Ошибка","В строку введено не число", QMessageBox::Ok);
    }

    no_auto_change = true;
}
