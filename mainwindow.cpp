#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupDVD();
    QTimer *myTimer = new QTimer();
    myTimer->setSingleShot(false);
    myTimer->start(1);
    connect(myTimer, &QTimer::timeout, this, &MainWindow::moveDVD);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupDVD()
{
   vert = UP;
   hor = LEFT;
   iconX = rand() % desktop->width() + 1;
   iconY = rand() % desktop->height() + 1;
}

void MainWindow::moveDVD()
{
   if (!dvd) return;
   if (iconX == 1 || iconX == desktop->width()) (lastHor == 0) ? hor = RIGHT : hor = LEFT;
   if (iconY == 1 || iconY == desktop->height()) (lastVert == 0) ? vert = DOWN : vert = UP;

   (vert == UP) ? iconY-- : iconY++;
   (hor == LEFT) ? iconX-- : iconX++;

   move(iconX, iconY);

   lastVert = vert;
   lastHor = hor;
}


void MainWindow::on_upButton_clicked()
{
    QRect r = frameGeometry();
    this->move((r.x()), (r.y() - pixel));
}

void MainWindow::on_downButton_clicked()
{
    QRect r = frameGeometry();
    this->move((r.x()), (r.y() + pixel));
}

void MainWindow::on_leftButton_clicked()
{
    QRect r = frameGeometry();
    this->move((r.x() - pixel), (r.y()));
}

void MainWindow::on_rightButton_clicked()
{
    QRect r = frameGeometry();
    this->move((r.x() + pixel), (r.y()));
}

void MainWindow::on_randomButton_clicked()
{
    std::random_device rdw;
    std::default_random_engine rw(rdw());
    std::uniform_int_distribution<int> disw(0, desktop->width());
    std::random_device rdh;
    std::default_random_engine rh(rdw());
    std::uniform_int_distribution<int> dish(0, desktop->height());

    this->move(disw(rh), dish(rw));
}

void MainWindow::on_dvdButton_toggled(bool checked)
{
    dvd = checked;
}
