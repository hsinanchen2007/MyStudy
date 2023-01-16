//檔案名稱：d:\C++10\C1002.cpp
#include <iostream>
#include <cstring>	//插入字串標題檔
using namespace std;

struct Booklist	//宣告Booklist資料結構
{
	char title[25];	//Booklist第1成員變數
	char auther[10];	//Booklist第2成員變數
	char number[10];	//Booklist第3成員變數
	float price;	//Booklist第4成員變數
};

int main(int argc, char** argv)
{
	Booklist CPP;	//建立Booklist型態變數
	strcpy(CPP.title, "C++全方位學習第三版");	//指定CPP第1成員初值
	strcpy(CPP.auther, "古頤榛\t");	//指定CPP第2成員初值
	strcpy(CPP.number, "AEL014632");	//指定CPP第3成員初值
	CPP.price = 580.00;	//指定CPP第4成員初值

	Booklist DL;	//建立Booklist型態變數
	strcpy(DL.title, "數位邏輯設計第三版");	//指定VB第1成員初值
	strcpy(DL.auther, "古頤榛\t");	//指定VB第2成員初值
	strcpy(DL.number, "AEE037000");	//指定VB第3成員初值
	DL.price = 420.00;	//指定VB第4成員初值

	cout.precision(2); cout.setf(ios::fixed);
	cout << "書名\t\t\t作者\t\t書號\t\t定價\n";
	cout << CPP.title << '\t';	//輸出CPP第1成員資料
	cout << CPP.auther << '\t';	//輸出CPP第2成員資料
	cout << CPP.number << '\t';	//輸出CPP第3成員資料
	cout << CPP.price << '\n';	//輸出CPP第4成員資料

	cout << DL.title << '\t';	//輸出VB第1成員資料
	cout << DL.auther << '\t';	//輸出VB第2成員資料
	cout << DL.number << '\t';	//輸出VB第3成員資料
	cout << DL.price << '\n';	//輸出VB第4成員資料
	return 0;
}
