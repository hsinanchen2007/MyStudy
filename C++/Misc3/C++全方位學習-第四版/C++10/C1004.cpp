//檔案名稱：d:\C++10\C1004.cpp
#include <iostream>
using namespace std;

struct Time		//宣告Time型態資料結構
{
	int hour;	//Time第1成員變數
	int minute;	//Time第2成員變數
	int second;	//Time第3成員變數
};

void printTime(int h, int m, int s);	//宣告函數原型

int main(int argc, char** argv)
{
	Time breakfast = {6, 30, 0};	//定義並起始breakfast
	Time lunch = {12, 0, 0};	//定義並起始lunch變數
	Time dinner = {18, 30, 0};	//定義並起始dinner變數
	Time supper = {22, 00, 0};	//定義並起始supper變數

	//呼叫print_time函數並傳遞結構成員資料
	cout << "Breakfast: ";
	printTime(breakfast.hour, breakfast.minute, breakfast.second);
	cout << "Lunch    : ";
	printTime(lunch.hour, lunch.minute, lunch.second);
	cout << "Dinner   : ";
	printTime(dinner.hour, dinner.minute, dinner.second);
	cout << "Supper   : ";
	printTime(supper.hour, supper.minute, supper.second);
	return 0;
}

void printTime(int h, int m, int s)	//輸出時間函數
{
	cout << ( (h==0 || h==12) ? 12 : (h%12) );	//輸出小時數
	cout << ':' << ( (m < 10) ? "0" : "" ) << m;	//輸出分鐘數
	cout << ':' << ( (s < 10) ? "0" : "" ) << s;	//輸出秒鐘數
	cout << ( h < 12 ? " AM" : " PM") << endl;	//輸出AM或PM
}
