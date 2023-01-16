//檔案名稱：d:\C++10\C1009.cpp
#include <iostream>
#include <iomanip>	//插入格式標題檔
using namespace std;


struct Date		//宣告Date型態資料結構
{
	int month;	//Date第1成員變數
	int day;	//Date第2成員變數
};

void printDate( Date * );	//宣告日期函數原型

int main(int argc, char** argv)
{
	Date newyear = {1, 1};	//定義並起始newyear
	Date women = {3, 8};	//定義並起始women
	Date children = {4, 4};	//定義並起始children
	Date national = {10, 10};	//定義並起始national
	Date christmas = {12, 25};	//定義並起始christmas

	cout << "元  旦：";
	printDate(&newyear);	//傳遞newyear變數位址
	cout << "婦女節：";
	printDate(&women);	//傳遞women變數位址
	cout << "兒童節：";
	printDate(&children);	//傳遞children變數位址
	cout << "國慶日：";
	printDate(&national);	//傳遞national變數位址
	cout << "聖誕節：";
	printDate(&christmas);	//傳遞christmas變數位址
	return 0;
}

void printDate( Date *d )	//輸出日期函數
{
	cout << setw(2) << d->month << " 月 ";	//輸出d的第1個成員
	cout << setw(2) << d->day << " 日";	//輸出d的第2個成員
	cout << endl;
}
