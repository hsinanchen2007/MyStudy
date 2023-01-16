//檔案名稱：d:\C++15\C1504.cpp
#include <iostream>
#include <fstream>
#include <cstring>	//包含strlen函數定義
using namespace std;

const char filename[] = "d:\\C++15\\C1504.txt";

class Note	//定義Note類別
{
	char outStr[81];
public:
	void write();	//宣告寫入文字檔原型
	void append();	//宣告附加文字檔原型
	void read();	//宣告讀取文字檔原型
};

void Note::write()	//定義寫入文字檔函數
{
	ofstream filePtr;
	filePtr.open(filename, ios::out);	//開啟輸出文字檔
	if(!filePtr) {
		cout << "開啟輸出檔錯誤！\n";
		system("PAUSE");
		exit(1);	//非正常結束程式
	} else {
		cout << "請輸入字串，連續按二次 Enter 則結束\n";
		cin.ignore();	//忽略輸入緩衝器的最後字
		while(1) {	//無窮迴圈
			cin.getline(outStr, 81);	//讀取整行文字
			if(!strlen(outStr) == 0)	//若字串長度不等於0
				filePtr << outStr << '\n';	//將文字寫入檔案
			else
				break;	//中斷迴圈
		}
	filePtr.close();
	}
}

void Note::append()	//定義附加文字檔函數
	{
	ofstream filePtr;
	filePtr.open(filename, ios::app);	//開啟附加文字檔
	if(!filePtr) {
		cout << "開啟附加檔錯誤！\n";
		system("PAUSE");
		exit(1);	//非正常結束程式
	} else {
		cout << "請輸入字串，連續按二次 Enter 則結束)\n";
		cin.ignore();	//忽略輸入緩衝器的最後字
		while(1) {	//無窮迴圈
			cin.getline(outStr, 81);	//讀取整行文字
			if(!strlen(outStr) == 0)	//若字串長度不等於0
				filePtr << outStr << '\n';	//將文字寫入檔案
			else
				break;	//中斷迴圈
		}
	}
	filePtr.close();
}

void Note::read()	//定義讀取文字檔函數
	{
	ifstream filePtr;
	filePtr.open(filename, ios::in);	//開啟輸入文字檔
	char inChar;
	if(!filePtr) {
		cout << "開啟輸入檔錯誤！\n";
		system("PAUSE");
		exit(1);	//非正常結束程式
	} else {
		while(filePtr.get(inChar))	//若讀取字串不等於空字串
			cout << inChar;	//輸出讀取的字串
	}
	filePtr.close();
}

int main(int argc, char** argv)
{
	Note text;	//建立Note物件
	char n;

	while(1)
	{
		cout << "1.寫入  2.附加  3.讀取  "	//Menu
			 << "0.結束  請選擇(1-3或0): ";
		cin >> n;

		switch (n)	//比較輸入值
		{
			case '1':	//若輸入值為1
				text.write();	//呼叫寫入文字檔函數
				break;
			case '2':	//若輸入值為2
				text.append();	//呼叫附加文字檔函數
				break;
			case '3':	//若輸入值為3
				text.read();	//呼叫讀取文字檔函數
				break;
			case '0':	//若輸入值為0
				return 0;	//正常結束程式
		}
	}
}
