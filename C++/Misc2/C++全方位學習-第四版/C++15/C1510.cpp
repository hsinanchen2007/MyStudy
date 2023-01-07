//檔案名稱：d:\C++15\C1510.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	ifstream filePtr;

	filePtr.open("d:\\C++15\\C1505.dat", ios::binary|ios::in);	//開啟輸入檔案
	if(!filePtr) {	//若開啟檔案錯誤
		cout << "開啟輸入檔錯誤！\n";
		system("PAUSE");
		exit(1);	//非正常結束程式
	} else {		//否則
		filePtr.seekg(0, ios::end);	//移動指標到檔尾
		int endpos = filePtr.tellg();	//取得指標位置
		cout << "d:\\C++15\\C1505.dat 的大小 = "
			<< endpos << " bytes" << endl;	//顯示檔案大小
	}
	filePtr.close();
	return 0;
}
