#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int penSize=1;

    //КРАСНЫЕ ЛИНИИ
//____________________________________________________
    QPen myPen(Qt::red, penSize, Qt::SolidLine);
    painter.setPen(myPen);
//    for (int i=1;i<=40;i++)
//    painter.drawLine(0, 20*i-7, 1200, 20*i-7);
//    for (int i=1;i<=60;i++)
//        painter.drawLine(20*i, 0, 20*i, 800);

    //БЕЛЫЕ ЛИНИИ
//____________________________________________________
    QPen mine(Qt::darkGray, 2, Qt::SolidLine);
    painter.setPen(mine);
    for (int i=0;i<=9;i++)
    painter.drawLine(23, 80*i+30, 743, 80*i+30);
    for (int i=0;i<=9;i++)
        painter.drawLine(80*i+23, 30, 80*i+23, 750);

    //БЕЛЫЕ КВАДРАТИКИ И ПРЯМОУГОЛЬНИК
//____________________________________________________
    painter.drawRect(780, 33, 380,  140);
    painter.drawRect(800, 53, 100,  100);
    painter.drawRect(920, 53, 100,  100);
    painter.drawRect(1040, 53, 100,  100);
}


    MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
            //СОЗДАНИЕ
        //____________________________________________________
        H = new QHBoxLayout;
        V = new QVBoxLayout;
        D = new QGridLayout;
        D->setVerticalSpacing(0);
        D->setHorizontalSpacing(0);

            //ВНЕСЕНИЕ КНОПОК
        //____________________________________________________
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                BallButton *pb=new BallButton;
    //            pb->setStyleSheet("QPushButton { background: none; border: none; outline: none; color: transparent; } ");
                pb->setFixedHeight(93);
                pb->setFixedWidth(93);
                pb->i=i;
                pb->j=j;
                this->pole[i][j]=pb;
                connect(pb, SIGNAL(clicked()), this, SLOT(ifclicked()));
                D->addWidget(pb,i,j);
            }
        }


           //НАСТРОЙКА ПОЛОЖЕНИЯ
        //____________________________________________________
        {
            QPushButton *pb=new QPushButton;
          pb->setFixedHeight(25);
          pb->setFixedWidth(740);
          pb->setText("Undo");
          V->addLayout(D);
          V->addWidget(pb);
        }

        {
            QPushButton *pb=new QPushButton;
            pb->setFixedHeight(0);
            pb->setFixedWidth(413);
            H->addLayout(V);
            H->addWidget(pb);
            delete ui->centralWidget->layout();
            ui->centralWidget->setLayout(H);
        }
        pole[0][0]->set_color(2);
    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }

//    void MainWindow::Del()
//    {

//    }

    void MainWindow::ifclicked()
    {
        BallButton *bashka = (BallButton*)sender();
        if ((N)&&(bashka->i==y)&&(bashka->j==x)) N=false;
        if ((!N)&&(bashka->now_color!=0))
        {
            x=bashka->j;
            y=bashka->i;
            N=true;
        }
        if ((N)&&(bashka->now_color==0))
        {
            bashka->set_color(pole[x][y]->now_color);
            pole[x][y]->set_color(0);
            N=false;
        }
//        qDebug() << bashka->i << bashka->j;
    }
