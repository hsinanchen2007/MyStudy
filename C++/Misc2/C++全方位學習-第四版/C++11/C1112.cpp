//�ɮצW�١Gd:\C++11\C1112.cpp
#include <iostream>
using namespace std;

class Calculate	//�w�qCalculate���O
{
	int x;
public:
	Calculate(int);	//�إߪ̨�ƭ쫬
	void sum(Calculate);	//�[�k�B���ƭ쫬
	void display();	//���x�Ȩ�ƭ쫬
};

Calculate::Calculate(int n)	//�w�q�إߪ̨��
{
	x = n;
}

void Calculate::sum(Calculate obj)	//�w�q�[�k�B����
{
	x += obj.x;
}

void Calculate::display()	//�w�q��� x �Ȩ��
{
	cout << x;
}

int main(int argc, char** argv)
{
	Calculate a(100), b(200);	//�w�q a.x=100,b.x=200
	a.display();	//��� a.x=100 ��
	cout << '+';	//��� + ��
	b.display();	//��� b.x=200 ��
	cout << '=';	//��� = ��
	a.sum(b);	//�p�� a.x = a.x + b.x
	a.display();	//��ܭp��� a.x=300 ��
	cout << endl;	//����
	return 0;
}
