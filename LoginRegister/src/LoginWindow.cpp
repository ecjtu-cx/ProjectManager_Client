#include "LoginWindow.h"

LoginWindow::LoginWindow()
{
	// 设置窗口大小
	this->setFixedSize(780, 520);
    // 设置窗口为无边框
	this->setWindowFlags(Qt::FramelessWindowHint);
}

LoginWindow::~LoginWindow()
{
}
