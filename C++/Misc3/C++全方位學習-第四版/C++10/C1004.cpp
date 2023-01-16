//�ɮצW�١Gd:\C++10\C1004.cpp
#include <iostream>
using namespace std;

struct Time		//�ŧiTime���A��Ƶ��c
{
	int hour;	//Time��1�����ܼ�
	int minute;	//Time��2�����ܼ�
	int second;	//Time��3�����ܼ�
};

void printTime(int h, int m, int s);	//�ŧi��ƭ쫬

int main(int argc, char** argv)
{
	Time breakfast = {6, 30, 0};	//�w�q�ð_�lbreakfast
	Time lunch = {12, 0, 0};	//�w�q�ð_�llunch�ܼ�
	Time dinner = {18, 30, 0};	//�w�q�ð_�ldinner�ܼ�
	Time supper = {22, 00, 0};	//�w�q�ð_�lsupper�ܼ�

	//�I�sprint_time��ƨöǻ����c�������
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

void printTime(int h, int m, int s)	//��X�ɶ����
{
	cout << ( (h==0 || h==12) ? 12 : (h%12) );	//��X�p�ɼ�
	cout << ':' << ( (m < 10) ? "0" : "" ) << m;	//��X������
	cout << ':' << ( (s < 10) ? "0" : "" ) << s;	//��X������
	cout << ( h < 12 ? " AM" : " PM") << endl;	//��XAM��PM
}
