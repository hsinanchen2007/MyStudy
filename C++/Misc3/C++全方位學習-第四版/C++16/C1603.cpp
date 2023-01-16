//檔案名稱：d:\C++16\C1603.cpp
#include <iostream>
using namespace std;

bool check(char i)	//含有throw的函數
{
	try {			//try
		if (i<'0' || i>'9') throw i;	//若輸入超出0-9則throw
		cout << "輸入值 = " << i << endl;	//顯示輸入值
		return true;
	} catch(char i) {	//chtch
		cout << "輸入值 = " << i << "，超出範圍！\n";	//顯示訊息
		return false;
	}
}

int main(int argc, char** argv)
{
	char n;
	do
	{
		cout << "請輸入0 - 9 的整數：";
		cin >> n;
	} while(check(n));	//呼叫check函數
	return 0;
}
