//檔案名稱：d:\C++15\C1501.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	ofstream filePtr;	//建立檔案物件(代號)
	filePtr.open("d:\\C++15\\C1501.txt", ios::out);	//開啟輸出檔C1501.txt
	if(!filePtr.is_open()) {	//若開啟檔案代號錯誤
		cout << "開啟檔案錯誤！\n";
		system("PAUSE");
		exit(1);	//非正常結束程式
	} else {		//否則
		filePtr << "Life is not easy, but in the long run \n";
		filePtr << "it's easier than going to elaborate ends \n";
		filePtr << "to deny it.\n";	//寫入字串到檔案
	}
	filePtr.close();	//關閉檔案物件(代號)
	return 0;
}
