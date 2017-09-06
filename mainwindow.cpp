#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProcess>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_copyFW_components()
{

}

void MainWindow::on_pushBtn_Copy_clicked()
{
    QProcess p(0);
    p.start("C:/Users/qingfeng/Desktop/copy_bin.bat");
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());

    QMessageBox testMassage;
    testMassage.setText(strTemp);
    testMassage.exec();
}
