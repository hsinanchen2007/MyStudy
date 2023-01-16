//檔案名稱：d:\C++10\C1005.cpp
#include <iostream>
using namespace std;

struct Time		//宣告Time型態資料結構
{
	int hour;	//Time第1成員變數
	int minute;	//Time第2成員變數
	int second;	//Time第3成員變數
};

void printTime( const Time &);	//宣告函數原型

int main(int argc, char** argv)
{
	Time breakfast = {6, 30, 0};	//定義並起始breakfast
	Time lunch = {12, 0, 0};	//定義並起始lunch變數
	Time dinner = {18, 30, 0};	//定義並起始dinner變數
	Time supper = {22, 00, 0};	//定義並起始supper變數

	cout << "Breakfast: ";
	printTime(breakfast);	//傳遞breakfast位址
	cout << "Lunch    : ";
	printTime(lunch);	//傳遞lunch變數位址
	cout << "Dinner   : ";
	printTime(dinner);	//傳遞dinner變數位址
	cout << "Supper   : ";
	printTime(supper);	//傳遞supper變數位址
	return 0;
}

void printTime( const Time &t )	//輸出時間函數
{
	cout << ( (t.hour==0 || t.hour==12) ? 12 : (t.hour%12) );
	cout << ':' << ( (t.minute < 10) ? "0" : "" ) << t.minute;
	cout << ':' << ( (t.second < 10) ? "0" : "" ) << t.second;
	cout << ( t.hour < 12 ? " AM" : " PM") << endl;
}
