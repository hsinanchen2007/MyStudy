//檔案名稱：d:\C++15\C1502.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	ofstream filePtr;	//建立檔案物件(代號)
	filePtr.open("d:\\C++15\\C1501.txt", ios::app);	//開啟d:\C++15\C1501.txt

	if(!filePtr.is_open()) {	//若開啟檔案代號錯誤
		cout << "開啟檔案錯誤！\n";
    	system("PAUSE");
		exit(1);	//非正常結束程式
	} else {	//否則
		filePtr << "人生的確不是簡單的，可是老老實實地活著，\n";	//附加字串到檔案
		filePtr << "總要比想出千方百計的逃避人生來得簡單些。\n";	//附加字串到檔案
	}
	filePtr.close();	//關閉檔案物件(代號)
	return 0;
}
