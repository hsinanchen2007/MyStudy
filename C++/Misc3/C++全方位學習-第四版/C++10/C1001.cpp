//�ɮצW�١Gd:\C++10\C1001.cpp
#include <iostream>
using namespace std;

struct Time		//�ŧi���A��Ƶ��c
{
	int hour;	//Time��1�����ܼ�
	int minute;	//Time��2�����ܼ�
	int second;	//Time��3�����ܼ�
};

int main(int argc, char** argv)
{
	Time midnight;	//�w�qTime���A�ܼ�
	midnight.hour = 12;	//���w��1�������
	midnight.minute = 0;	//���w��2�������
	midnight.second = 0;	//���w��3�������

	cout << "�ȩ]�зǮɶ��G";
	cout << midnight.hour << ':' ;	//��X��1�������
	cout << "0" << midnight.minute << ':' ;	//��X��2�������
	cout << "0" << midnight.second << " AM";	//��X��3�������
	cout << endl;
	return 0;
}
