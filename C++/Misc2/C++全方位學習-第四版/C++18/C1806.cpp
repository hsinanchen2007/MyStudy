//�x�s�ɦW�Gd:\C++18\C1806.cpp
#include <iostream>
using namespace std;

class Division
{
	int a, b, q;
public:
	Division(int a1, int b1)
	{
		a = a1;
		b = b1;
		q = 0;
	}
	int quotient()
	{
		if(a>=b) {	//a���j�󵥩�b
			a -= b;	//a = a - b
			q++;
			return quotient();	//���^�I�s
		} else
			return q;	//�Ǧ^�Ӽ�
	}
	int remainder()
	{
		if(a>=b) {	//a���j�󵥩�b
			a -= b;	//a = a - b
			return remainder();	//���^�I�s
		} else
			return a;	//�Ǧ^�l��
	}
};

int main(int argc, char** argv)
{
	int a, b;	//�ŧi�ܼ�
	cout << "�п�J�G�Ӿ�� (a b)�G";	//��X�T��
	cin >> a >> b;	//��Ja, b�G��
	Division div(a, b);

	cout << a << " / " << b << " = " << div.quotient();		//��X��
	cout << " R " << div.remainder() << endl;		//��X�l��
	return 0;
}
