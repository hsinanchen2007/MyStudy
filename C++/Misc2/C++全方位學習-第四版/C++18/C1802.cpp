//�x�s�ɦW�Gd:\C++18\C1802.cpp
#include <iostream>
using namespace std;

int gcd(int, int, int);

int main(int argc, char** argv)
{
	int a, b, n;	//�ŧi�ܼ�
	cout << "�п�J�G�Ӿ�� (a b)�G";	//��X�T��
	cin >> a >> b;	//��Ja, b�G��
	n = a;
	cout << "GCD = " << gcd(a, b, n) << endl;		//��XGCD
	return 0;
}

int gcd(int a, int b, int n)
{
	if(a%n==0 && b%n==0)	//�G�ư��Hn�ҵ���0
		return n;
	else
		return gcd(a, b, n-1);
}
