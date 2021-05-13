#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QString>
#include <QQmlContext>
using namespace std;



//Connect with bash-------
std::string com1()
{
    string cmd="lscpu";
    string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
      while (!feof(stream))
        if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
      pclose(stream);
    }
  cout << "LS: " << data << endl;

    const std::string s = data;
    return s;
}

std::string com2()
{
    string cmd="lspci";
    string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
      while (!feof(stream))
        if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
      pclose(stream);
    }
  cout << "LS: " << data << endl;

    const std::string s = data;
    return s;
}
//const QString s = QString::fromStdString( com1() );
//ui->statusbar->showMessage(s);
//---------- --------




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{



    ui->setupUi(this);
    const QString s1 = QString::fromStdString( com1() );
    ui-> textBrowser_2->append(s1);

    const QString s2 = QString::fromStdString( com2() );
    ui-> textBrowser_3->append(s2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_gobtn_clicked()
{

        ui->webEngineView->load(ui->urledit->text());
 system("notify-send 'Loading..' \"Lets gooo.... :P\"");
}

void MainWindow::on_urledit_returnPressed()
{
   on_gobtn_clicked();

}

void MainWindow::on_webEngineView_loadStarted()
{
    ui->statusbar->showMessage("Loading your damn webpage...");
}


void MainWindow::on_webEngineView_loadFinished(bool)
{
    ui->statusbar->showMessage("Loaddddd.");

}



