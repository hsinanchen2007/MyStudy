//�ɮצW�١Gd:\C++10\C1005.cpp
#include <iostream>
using namespace std;

struct Time		//�ŧiTime���A��Ƶ��c
{
	int hour;	//Time��1�����ܼ�
	int minute;	//Time��2�����ܼ�
	int second;	//Time��3�����ܼ�
};

void printTime( const Time &);	//�ŧi��ƭ쫬

int main(int argc, char** argv)
{
	Time breakfast = {6, 30, 0};	//�w�q�ð_�lbreakfast
	Time lunch = {12, 0, 0};	//�w�q�ð_�llunch�ܼ�
	Time dinner = {18, 30, 0};	//�w�q�ð_�ldinner�ܼ�
	Time supper = {22, 00, 0};	//�w�q�ð_�lsupper�ܼ�

	cout << "Breakfast: ";
	printTime(breakfast);	//�ǻ�breakfast��}
	cout << "Lunch    : ";
	printTime(lunch);	//�ǻ�lunch�ܼƦ�}
	cout << "Dinner   : ";
	printTime(dinner);	//�ǻ�dinner�ܼƦ�}
	cout << "Supper   : ";
	printTime(supper);	//�ǻ�supper�ܼƦ�}
	return 0;
}

void printTime( const Time &t )	//��X�ɶ����
{
	cout << ( (t.hour==0 || t.hour==12) ? 12 : (t.hour%12) );
	cout << ':' << ( (t.minute < 10) ? "0" : "" ) << t.minute;
	cout << ':' << ( (t.second < 10) ? "0" : "" ) << t.second;
	cout << ( t.hour < 12 ? " AM" : " PM") << endl;
}
