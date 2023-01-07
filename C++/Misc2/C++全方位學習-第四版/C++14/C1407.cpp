//�ɮצW�١Gd:\C++14\C1407.cpp
#include <iostream>
using namespace std;

class Base
{
protected:
	int i;
};

class Derived1: virtual public Base	//�ŧivirtual�~��Base
{
protected:
	int j;
};

class Derived2: virtual public Base	//�ŧivirtual�~��Base
{
protected:
	int k;
};

class Derived3: public Derived1, public Derived2
{
protected:
	int sum;
public:
	Derived3(int n1, int n2, int n3)
	{
		i = n1;	//�OBase::i = n1
		j = n2;	//�ODerived1::j = n2
		k = n3;	//�ODerived2::k = n3
		sum = i + j + k;	//�Osum=i+j+k
	}
	void show()
	{
		cout << "i = " << i << endl;	//��XBase::i
		cout << "j = " << j << endl;	//��XDerived1::j
		cout << "k = " << k << endl;	//��XDerived2::k
		cout << "sum = " << sum << endl;	//��XDerived3::sum
	}
};

int main(int argc, char** argv)
{
	Derived3 d3(10, 20, 30); 	//�إ�Derived3����d3
	d3.show();	//�I�sDerived3::show
	return 0;
}
