//檔案名稱：d:\C++15\C1503.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	ifstream filePtr;	//建立檔案物件(代號)
	char inData;	//存放資料緩衝區

	filePtr.open("d:\\C++15\\C1501.txt", ios::in);	//開啟d:\C++15\C1501.txt

	if(!filePtr) {	//若開啟檔案代號錯誤
		cout << "開啟檔案錯誤！\n";
		system("PAUSE");
		exit(1);	//非正常結束程式
	} else {		//若開啟檔案代號正確
		while(filePtr.get(inData)) {	//取得資料並存入緩衝區
			cout << inData;	//顯示資料
		}
	}
	filePtr.close();	//關閉檔案物件(代號)
	return 0;
}
