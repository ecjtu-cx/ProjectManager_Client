#include <QApplication>
#include <QMainWindow>
#include "ServerCheckWindow.h"
#include "ElaApplication.h"
#include "ElaWindow.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	ElaApplication::getInstance()->init();
	ElaWindow w;
	//ServerCheckWindow w;
	w.show();
	return a.exec();
}

//git config --global http.https://github.com.proxy socks5://127.0.0.1:7897
// git config --global http.https://github.com.proxy 'http://127.0.0.1:7897'
//git config --global --unset http.https://github.com.proxy