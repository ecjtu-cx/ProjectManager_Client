#include "ServerCheckWindow.h"

ServerCheckWindow::ServerCheckWindow() {
	// 初始化控件
	mainLabel = new QLabel(this);
	serverLineEdit = new QLineEdit(this);
	checkButton = new QPushButton(this);
	exitButton = new QPushButton(this);
	// 调用函数初始化界面外观
	initUI();
	// 连接信号槽
	connectSlots();
}

ServerCheckWindow::~ServerCheckWindow() {}

void ServerCheckWindow::initUI() {
	// 设置窗口大小
	this->setFixedSize(710, 400);
	// 设置窗口为无边框
	this->setWindowFlags(Qt::FramelessWindowHint);
	// 设置窗口透明背景 - 这一点非常关键
	this->setAttribute(Qt::WA_TranslucentBackground);
	// 设置主标题
	mainLabel->setGeometry(230, 50, 250, 50);
	mainLabel->setText("服务器认证");
	mainLabel->setStyleSheet("font-size: 50px; color: #000000; font-family: BlueakaBetaGBK;");
	mainLabel->setAlignment(Qt::AlignCenter);
	// 设置服务器地址输入框
	serverLineEdit->setGeometry(160, 150, 390, 50);
	serverLineEdit->setPlaceholderText("请输入服务器地址");
	serverLineEdit->setStyleSheet("font-size: 25px; color: black; font-family: BlueakaBetaGBK; border: none; background-color: #C7EEF5; border-radius:20px;");
	serverLineEdit->setAlignment(Qt::AlignCenter);
	// 设置确认按钮
	checkButton->setGeometry(150, 250, 150, 50);
	checkButton->setText("确认");
	checkButton->setStyleSheet(
		"QPushButton{font-size: 25px; color: #000000; font-family: BlueakaBetaGBK; border: none; background-color: #C7EEF5; border-radius:20px;}"
		"QPushButton:hover {background-color: #F21207 }"
	);
	// 设置退出按钮
	exitButton->setGeometry(410, 250, 150, 50);
	exitButton->setText("退出");
	exitButton->setStyleSheet(
		"QPushButton{font-size: 25px; color: #000000; font-family: BlueakaBetaGBK; border: none; background-color: #C7EEF5; border-radius:20px;}"
		"QPushButton:hover {background-color: #F21207 }"
	);
}

void ServerCheckWindow::connectSlots() {
	// 退出按钮点击事件
	connect(exitButton, &QPushButton::clicked, [this] {this->close(); });
	// 确认按钮点击事件
	connect(checkButton, &QPushButton::clicked, [this] {
		// 获取服务器地址
		QString serverAddress = serverLineEdit->text();
		// 判断服务器地址是否为空
		if (serverAddress.isEmpty()) {
			QMessageBox::warning(this, "警告", "服务器地址不能为空！");
			return;
		}
		// 连接服务器
		QNetworkAccessManager* manager = new QNetworkAccessManager(this);
		QNetworkRequest request;
		request.setUrl(QUrl("http://" + serverAddress + "/server/check"));
		QNetworkReply* reply = manager->get(request);
		// 连接服务器返回数据的信号槽
		connect(reply, &QNetworkReply::finished, [this, reply] {
			// 获取服务器返回的数据
			QByteArray data = reply->readAll();
			qDebug() << data;
			// 判断服务器返回的数据
			if (data == "true") {
				QMessageBox::information(this, "提示", "服务器认证成功！");
			}
			else {
				QMessageBox::warning(this, "警告", "服务器认证失败！");
			}
			// 释放资源
			reply->deleteLater();
			});
		});
}
// 重写绘制事件
void ServerCheckWindow::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿
	// 创建圆角矩形路径
	QPainterPath path;
	path.addRoundedRect(rect(), 15, 15);
	// 使用画刷填充整个路径
	painter.fillPath(path, QColor(47, 242, 165));
}