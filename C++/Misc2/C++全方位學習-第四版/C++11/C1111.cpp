//�ɮצW�١Gd:\C++11\C1111.cpp
#include <iostream>
using namespace std;

class Oddsum
{
	static int sum;	//�ŧi�R�A��Ʀ���
public:
	static void addition(int n);	//�ŧi�R�A�������
	void display();	//�ŧi��X��ƨ��
};

int Oddsum::sum = 0;	//�_�l�R�A��Ʀ���

void Oddsum::addition(int n) {	//�w�q�R�A�������
	sum += n;	//sum(n+1)=sum(n)+n
}

void Oddsum::display() {	//�w�q��X��Ʀ������
	cout << "sum = " << sum << endl;
}

int main(int argc, char** argv)
{
	Oddsum a;
	for (int count = 1; count <= 100; count += 2)	//�I�s��ưj��
		a.addition(count);	//�I�saddition���
	a.display();	//�I�sdisplay���
	return 0;
}
