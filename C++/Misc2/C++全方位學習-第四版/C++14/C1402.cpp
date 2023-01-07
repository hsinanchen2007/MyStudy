//�ɮצW�١Gd:\C++14\C1402.cpp
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
	void show() {	//��¦���O��k
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
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
	void show() {	//�l�����O�W����k
		Base::show();
		cout << "c = " << c << endl;
	}
};

int main(int argc, char** argv)
{
	Derived d(2, 3, 5);	//�إ�Derived����d
	d.show();	//�I�sDerived�h����k
	return 0;
}
