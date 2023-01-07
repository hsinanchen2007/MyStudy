//檔案名稱：d:\C++11\C1105.cpp
#include <iostream>
using namespace std;

class Time		//宣告Time類別
{
	int hour;	//私有資料成員
	int minute;	//私有資料成員
	int second;	//私有資料成員
public:
	void set_time(int h, int m, int s)	//設定時間成員函數
	{
		hour = h;
		minute = m;
		second = s;
	}
	void print_time( const Time &t )	//顯示時間成員函數
	{
		cout << ( (hour==0 || hour==12) ? 12 : (hour%12) )
			<< ':' << ( (minute < 10) ? "0" : "" ) << minute
			<< ':' << ( (second < 10) ? "0" : "" ) << second
			<< ( hour < 12 ? " AM" : " PM") << endl;
	}
};

int main(int argc, char** argv)
{
	Time midnight;	//定義物件midnight
	midnight.set_time(0, 0, 0);	//呼叫set_time函數
	cout << "午夜標準時間：";
	midnight.print_time(midnight);	//呼叫print_time函數
	return 0;
}
