//�ɮצW�١Gd:\C++12\C1201.cpp
#include <iostream>
using namespace std;

int area(int l, int w)	//�p�����έ��n���
{
	return l * w;
}

int area(int l, int w, int h)	//�p���������n���
{
	return 2 * ((l * w) + (w * h) + (h * l));
}

int main(int argc, char** argv)
{
	cout << "����έ��n = " << area(6, 8);	//��X����έ��n
	cout  << "���褽��\n";
	cout << "��������n = " << area(6, 8, 10);	//��X��������n
	cout  << "���褽��\n";
	return 0;
}
