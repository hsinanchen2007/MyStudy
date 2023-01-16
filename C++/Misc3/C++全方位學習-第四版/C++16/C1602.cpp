//檔案名稱：d:\C++16\C1602.cpp
#include <iostream>
using namespace std;

void check(char i)	//含有throw的函數
{
	if (i<'0' || i>'9') throw i;	//若輸入超出0-9則throw
	cout << "輸入值 = " << i << endl;	//顯示輸入值
}

int main(int argc, char** argv)
{
	char n;
	while (1)
	{
		cout << "請輸入0 - 9 的整數：";
		cin >> n;
		try {			//try
			check(n);	//呼叫check函數
		}
		catch(char i) {	//chtch
			cout << "輸入值 = " << i << "，超出範圍！\n";	//顯示訊息
			return 1;	//非正常結束程式
		}
	}
	return 0;	//正常結束程式 
}
