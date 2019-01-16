#include "ballbutton.h"

BallButton::BallButton()
{
    now_color = 0;
}

void BallButton::set_color(int color)// 0 - delete
{
    now_color=color;
    if (color==0)
    {
        this->setIcon(QIcon());
    }
    if (color==1)
    {
        this->setIcon(QIcon(":/resource/images/Ball1.png"));
    }
    if (color==2)
    {
        this->setIcon(QIcon(":/resource/images/Ball2.png"));
    }
    if (color==3)
    {
        this->setIcon(QIcon(":/resource/images/Ball3.png"));
    }
    now_color=color;
    this->setIconSize(QSize(123, 123));
}


