#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QString>
#include <QQmlContext>
#include <unistd.h>
#include <ios>
#include <fstream>
#include <string>
#include <QFileDialog>
#include <QProcess>
#include <QFile>
#include <QWebEngineSettings>
#include <QWebEngineHistory>

#include <QTextStream>
using namespace std;


//const QString s = QString::fromStdString( com1() );
//ui->statusbar->showMessage(s);
//---------- --------




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{



    ui->setupUi(this);
    QProcess p;
    p.QProcess::start("lscpu");
    p.waitForFinished(-1);
    ui->textBrowser_2->append(p.readAllStandardOutput());

    QProcess p1;
    p1.QProcess::start("lspci");
    p1.waitForFinished(-1);
    ui->textBrowser_3->append(p1.readAllStandardOutput());

    QProcess p2;
    p2.QProcess::start("ip", QStringList() << "addr");
    p2.waitForFinished(-1);
    ui->textBrowser_4->append(p2.readAllStandardOutput());


}



//QString MainWindow::convert(QUrl input)
//{
//QString Input; Input = input.toEncoded();

//return(Input);
//}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_gobtn_clicked()
{

        ui->webEngineView->load(ui->urledit->text());
 system("notify-send 'Loading..' \"Lets gooo....\"");
}

void MainWindow::on_urledit_returnPressed()
{
   on_gobtn_clicked();

}

void MainWindow::on_webEngineView_loadStarted()
{
    ui->statusbar->showMessage("Loading...");
}


void MainWindow::on_webEngineView_loadFinished(bool)
{
    ui->statusbar->showMessage("Loaded");

}




void MainWindow::on_pushButton_5_clicked()
{
  ui-> textBrowser->clear();

}



void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->webEngineView->setZoomFactor(position);
}


void MainWindow::on_pushButton_8_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                       "Open Text File", ".", "Text files (*)" );
    if ( fileName.isEmpty() )
      return;

    QFile file( fileName );
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       return;

    QTextStream in( &file );
    ui->textEdit->clear();
    while (!in.atEnd()) {
       QString line = in.readLine();
       ui->textEdit->append( line );
    }
}


void MainWindow::on_pushButton_13_clicked()
{

  QUrl url=QUrl("http://google.com");

  ui->webEngineView->load(url);
}


void MainWindow::on_pushButton_14_clicked()
{
    QUrl url=QUrl("https://github.com/RNA3210d/Qt-webengineview-simple-browser");

    ui->webEngineView->load(url);
}


void MainWindow::on_webEngineView_urlChanged(const QUrl &arg1)
{

}


void MainWindow::on_pushButton_16_clicked()
{
    QString ping=ui->lineEdit->text();


        QProcess* ping_process = new QProcess(this);
        connect(ping_process, &QProcess::readyReadStandardOutput, [=] {
            ui->textBrowser_5->append(ping_process->readAllStandardOutput());
        });
        ui->statusbar->showMessage("Ping test running....");
        ping_process->QProcess::start("ping", QStringList() << ping);
}



