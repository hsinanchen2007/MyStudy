// BAndD.cpp
// --------------------------------------
#include "BD.h"
int main()
{
	cout << "sizeof(Base)/sizeof(int)   : " 
		    << sizeof(Base)/sizeof(int) << endl;
	cout << "sizeof(Derived)/sizeof(int): " 
		    << sizeof(Derived)/sizeof(int) << endl;
	cout << "���� �uDerived X�v  ����: " << endl;
	Derived X;
	cout << "X.GetBase():   " << X.GetBase() << endl;
	cout << "X.Get()    :   " << X.Get()     << endl;
	X.SetBase(7);
	X.Set(9);
	cout << "����uX.SetBase(7)�v�M�uX.Set(9)�v ����: "
		    << endl;
	cout << "X.GetBase():   " << X.GetBase() << endl;
	cout << "X.Get()    :   " << X.Get()     << endl;
	X.Double();
	cout << "���� �uX.Double()�v ����: " << endl;
	cout << "X.GetBase():   " << X.GetBase() << endl;
	cout << "X.Get()    :   " << X.Get()     << endl;
	X.Triple();
	cout << "���� �uX.Triple()�v ����: " << endl;
	cout << "X.GetBase():   " << X.GetBase() << endl;
	cout << "X.Get()    :   " << X.Get()     << endl;
	Derived Y(12,25);
	cout << "���� �uDerived Y(12,25)�v ����: " << endl;
	cout << "Y.GetBase():   " << Y.GetBase()  << endl;
	cout << "Y.Get()    :   " << Y.Get()      << endl;
	system("pause");
	return 0;
}
