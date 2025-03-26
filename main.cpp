#include <QApplication>
#include <QMainWindow>
#include "ServerCheckWindow.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	ServerCheckWindow w;
	
	w.show();
	return a.exec();
}