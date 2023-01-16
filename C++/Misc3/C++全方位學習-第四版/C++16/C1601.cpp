//檔案名稱：d:\C++16\C1601.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char ps[9] = "year2021";
	char str[9];
	cout << "請輸入密碼：";
	cin >> str;
	try {
		for(int i=0; i<9; i++)
			if (str[i] != ps[i])	//若密碼錯誤
				throw i;	//則投擲例外
		cout << "密碼正確！\n";	//顯示正確訊息
	}
	catch(int i) {	//捕捉例外
		cout << "密碼錯誤！\n";	//顯示錯誤訊息
	}
	return 0;
}
