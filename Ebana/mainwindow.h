#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <ballbutton.h>
#include <QPainter>
#include <QPicture>
#include <QtDebug>
#include <QLabel>
#include <iostream>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    BallButton* pole[9][9];
    int BallCount;
    QHBoxLayout * H;
    QVBoxLayout * V;
    QGridLayout * D;
    int x;
    int y;
    bool N=false;
public slots:
    void ifclicked();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
