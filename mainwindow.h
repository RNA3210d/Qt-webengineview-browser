#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_gobtn_clicked();

    void on_webEngineView_loadStarted();

    void on_webEngineView_loadFinished(bool arg1);

    void on_urledit_returnPressed();

    void on_pushButton_5_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_8_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_webEngineView_urlChanged(const QUrl &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
