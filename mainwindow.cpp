#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QtCore>
#include <QIODevice>
#include <QDir>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir dir;
    foreach(QFileInfo mItm, dir.drives()){ //C:/ D:/ 
        qDebug()<<mItm.absoluteFilePath();

}

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()  //ფოლდერის შექმნა
{
    QString name = ui->lineEdit->text();
    QDir dir;
    QString path = "C:/Users/nikusha/Desktop/" + name;
    if(!dir.exists(path)){
        dir.mkpath(path);
        QMessageBox::information(this,"ინფორმაცია", "ფოლდერი შეიქმნა");
    }
    else {
        QMessageBox::information(this,"ინფორმაცია", "ფოლდერი არ შეიქმნა");
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    QDir dir("C:/Users/nikusha/Desktop/nika");
    foreach(QFileInfo mItm , dir.entryInfoList()){  //ფოლდერში ფაილების ნახვა
        QString temp = mItm.absoluteFilePath();
        //ui->plainTextEdit->setPlainText(temp);
        qDebug()<<mItm.absoluteFilePath();

        }
   }
void MainWindow::on_pushButton_3_clicked()  //ფოლდერში ფაილის წაშლა
{
     QString name = ui->lineEdit->text();
    QDir dir("C:/Users/nikusha/Desktop/nika");
    if(dir.exists(ui->lineEdit->text()+".txt")){
        dir.remove(ui->lineEdit->text()+".txt");
        QMessageBox::information(this,"ინფორმაცია", "ფაილი წაიშალა");


    }
    else{ QMessageBox::information(this,"ინფორმაცია","ფაილი არ არსებობს");

    }


}

void MainWindow::on_pushButton_5_clicked()  //ფაილზე სახელის შეცვლა
{
     if(!b){
   QString name = ui->lineEdit->text();
   QString name1 = ui->lineEdit_2->text();

   QFile file("C:/Users/nikusha/Desktop/"+name+".txt");
   file.rename("C:/Users/nikusha/Desktop/"+name1+".txt"); //სახელის დარქმევა
   QMessageBox::information(this,"ინფორმაცია" , "სახელი შეიცვლა");

   }
  if(b){
     QMessageBox::information(this,"ინფორმაცია" , "სახელი  არ შეიცვლა");

}
}
void MainWindow::on_pushButton_4_clicked() // ფაილის შექმნა
{
    QString name = ui->lineEdit->text();
   QFile file("C:/Users/nikusha/Desktop/" + name + ".txt");
   if(file.open(QIODevice::WriteOnly |QIODevice::Text)){  //ფაილის შექმნა
       QMessageBox::information(this, "ინფორმაცია", "ფაილი შეიქმნა");
  }
   else{
       QMessageBox::information(this, "ინფორმაცია" , "ფაილი არ შექმნილა");
   }
}
