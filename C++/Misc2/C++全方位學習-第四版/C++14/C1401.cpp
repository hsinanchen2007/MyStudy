//�ɮצW�١Gd:\C++14\C1401.cpp
#include <iostream>
using namespace std;

class Base	//�ŧi��¦���O
{
private:
	int a, b;
public:
	Base(int l, int m) {	//��¦���O�إߪ�
		a = l; b = m;
	}
	void show(char str1[], char str2[]) {	//��¦���O��k
		cout << str1 << a << endl;
		cout << str2 << b << endl;
	}
};

class Derived: public Base	//�ŧi�l�����O
{
private:
	int c;
public:
	Derived(int l, int m, int n): Base(l, m) {	//�l�����O�إߪ�
		c = n;
	}
	void show(char str3[]) {	//�l�����O�h����k
		cout << str3 << c << endl;
	}
};

int main(int argc, char** argv)
{
	Derived d(2, 3, 5);	//�إ�Derived����d
	char s1[] = "a = ";	//�w�q�ð_�ls1�r��
	char s2[] = "b = ";	//�w�q�ð_�ls2�r��
	char s3[] = "c = ";	//�w�q�ð_�ls3�r��
	d.Base::show(s1, s2);	//�I�sBase��k
	d.Derived::show(s3);	//�I�sDerived�h����k
	return 0;
}
