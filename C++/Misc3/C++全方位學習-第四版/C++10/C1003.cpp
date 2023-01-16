//檔案名稱：d:\C++10\C1003.cpp
#include <iostream>
using namespace std;

struct Booklist	//宣告Booklist資料結構
{
	char title[21];	//Booklist第1成員變數
	char auther[7];	//Booklist第2成員變數
	char number[10];	//Booklist第3成員變數
	float price;	//Booklist第4成員變數
};

int main(int argc, char** argv)
{
	//定義並起始CPP資料
	Booklist CPP = {"C++全方位學習第三版", "古頤榛", "AEL014632", 580.00};
	//定義並起始VB資料
	Booklist DL = {"數位邏輯設計第三版  ", "古頤榛", "AEE037000", 420.00};

	cout.precision(2); cout.setf(ios::fixed);
	cout << "書名\t\t\t作者\t\t書號\t\t定價\n";
	cout << CPP.title << '\t';	//輸出CPP第1成員資料
	cout << CPP.auther << "\t\t";	//輸出CPP第2成員資料
	cout << CPP.number << '\t';	//輸出CPP第3成員資料
	cout << CPP.price << '\n';	//輸出CPP第4成員資料

	cout << DL.title << '\t';	//輸出DL第1成員資料
	cout << DL.auther << "\t\t";	//輸出DL第2成員資料
	cout << DL.number << '\t';	//輸出DL第3成員資料
	cout << DL.price << '\n';	//輸出DL第4成員資料
	return 0;
}
