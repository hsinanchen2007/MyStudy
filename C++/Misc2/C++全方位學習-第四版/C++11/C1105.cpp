//�ɮצW�١Gd:\C++11\C1105.cpp
#include <iostream>
using namespace std;

class Time		//�ŧiTime���O
{
	int hour;	//�p����Ʀ���
	int minute;	//�p����Ʀ���
	int second;	//�p����Ʀ���
public:
	void set_time(int h, int m, int s)	//�]�w�ɶ��������
	{
		hour = h;
		minute = m;
		second = s;
	}
	void print_time( const Time &t )	//��ܮɶ��������
	{
		cout << ( (hour==0 || hour==12) ? 12 : (hour%12) )
			<< ':' << ( (minute < 10) ? "0" : "" ) << minute
			<< ':' << ( (second < 10) ? "0" : "" ) << second
			<< ( hour < 12 ? " AM" : " PM") << endl;
	}
};

int main(int argc, char** argv)
{
	Time midnight;	//�w�q����midnight
	midnight.set_time(0, 0, 0);	//�I�sset_time���
	cout << "�ȩ]�зǮɶ��G";
	midnight.print_time(midnight);	//�I�sprint_time���
	return 0;
}
