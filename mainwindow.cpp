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
#include <QFile>
#include <QWebEngineSettings>
#include <QWebEngineHistory>

#include <QTextStream>
using namespace std;




//std::string com12(double& vm_usage, double& resident_set)
//{
//   vm_usage = 0.0;
//   resident_set = 0.0;
//   ifstream stat_stream("/proc/self/stat",ios_base::in); //get info from proc
//   directory
//   //create some variables to get info
//   string pid, comm, state, ppid, pgrp, session, tty_nr;
//   string tpgid, flags, minflt, cminflt, majflt, cmajflt;
//   string utime, stime, cutime, cstime, priority, nice;
//   string O, itrealvalue, starttime;
//   unsigned long vsize;
//   long rss;
//   stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
//   >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
//   >> utime >> stime >> cutime >> cstime >> priority >> nice
//   >> O >> itrealvalue >> starttime >> vsize >> rss; // don't care
//   about the rest
//   stat_stream.close();
//   long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // for x86-64 is configured
//   to use 2MB pages
//   vm_usage = vsize / 1024.0;
//   resident_set = rss * page_size_kb;
//     cout << "Virtual Memory: " << vm_usage << "\nResident set size: " << resident_set << endl;
//}
//int main() {
//   double vm, rss;
//   mem_usage(vm, rss);
//   cout << "Virtual Memory: " << vm << "\nResident set size: " << rss << endl;
//}

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

