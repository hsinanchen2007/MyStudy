//檔案名稱：d:\C++10\C1001.cpp
#include <iostream>
using namespace std;

struct Time		//宣告型態資料結構
{
	int hour;	//Time第1成員變數
	int minute;	//Time第2成員變數
	int second;	//Time第3成員變數
};

int main(int argc, char** argv)
{
	Time midnight;	//定義Time型態變數
	midnight.hour = 12;	//指定第1成員初值
	midnight.minute = 0;	//指定第2成員初值
	midnight.second = 0;	//指定第3成員初值

	cout << "午夜標準時間：";
	cout << midnight.hour << ':' ;	//輸出第1成員資料
	cout << "0" << midnight.minute << ':' ;	//輸出第2成員資料
	cout << "0" << midnight.second << " AM";	//輸出第3成員資料
	cout << endl;
	return 0;
}
