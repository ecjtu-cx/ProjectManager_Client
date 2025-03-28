// Last update: 2025-3-27 by 程曦
#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>
#include <QUrlQuery>
class ServerCheckWindow : public QWidget {
	Q_OBJECT
public:
	ServerCheckWindow();
	~ServerCheckWindow();
private:
	void initUI();                                // 初始化界面
	void paintEvent(QPaintEvent* event) override; // 绘制界面
	void connectSlots();                          // 连接信号槽
private:
	QLabel* mainLabel;         // 界面的主标签
	QLineEdit* serverLineEdit; // 服务器地址输入框
	QPushButton* checkButton;  // 确认按钮
	QPushButton* exitButton;   // 退出按钮
};