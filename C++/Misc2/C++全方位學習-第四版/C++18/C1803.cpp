//�x�s�ɦW�Gd:\C++18\C1803.cpp
#include <iostream>
using namespace std;

int lcm(int, int, int);

int main(int argc, char** argv)
{
	int a, b, n;	//�ŧi�ܼ�
	cout << "�п�J�G�Ӿ�� (a b)�G";	//��X�T��
	cin >> a >> b;	//��Ja, b�G��
	n = a;
	cout << "LCM = " << lcm(a, b, n) << endl;		//��XLCM
	return 0;
}

int lcm(int a, int b, int n)
{
	if(n%b==0)	//n���Hb����0
		return n;
	else
		return lcm(a, b, n+a);
}
