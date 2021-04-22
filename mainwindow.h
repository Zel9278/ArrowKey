#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QDesktopWidget>
#include <QApplication>
#include <QTimer>
#include <random>
#include <iostream>

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
     void setupDVD();
     void moveDVD();
     void on_upButton_clicked();
     void on_downButton_clicked();
     void on_leftButton_clicked();
     void on_rightButton_clicked();
     void on_randomButton_clicked();
     void on_dvdButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int pixel = 50;
    bool dvd = false;

    int iconX, iconY;
    enum Vertical {UP,DOWN}vert;
    enum Horizontal {LEFT,RIGHT}hor;
    int lastVert;
    int lastHor;
};
#endif // MAINWINDOW_H
