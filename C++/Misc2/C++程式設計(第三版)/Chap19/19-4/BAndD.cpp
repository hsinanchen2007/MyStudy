// BAndD.cpp
// --------------------------------------
#include "BD.h"
int main()
{
	cout << "sizeof(Base)/sizeof(int)   : " 
		    << sizeof(Base)/sizeof(int) << endl;
	cout << "sizeof(Derived)/sizeof(int): " 
		    << sizeof(Derived)/sizeof(int) << endl;
	cout << "執行 「Derived X」  之後: " << endl;
	Derived X;
	cout << "X.GetBase():   " << X.GetBase() << endl;
	cout << "X.Get()    :   " << X.Get()     << endl;
	X.SetBase(7);
	X.Set(9);
	cout << "執行「X.SetBase(7)」和「X.Set(9)」 之後: "
		    << endl;
	cout << "X.GetBase():   " << X.GetBase() << endl;
	cout << "X.Get()    :   " << X.Get()     << endl;
	X.Double();
	cout << "執行 「X.Double()」 之後: " << endl;
	cout << "X.GetBase():   " << X.GetBase() << endl;
	cout << "X.Get()    :   " << X.Get()     << endl;
	X.Triple();
	cout << "執行 「X.Triple()」 之後: " << endl;
	cout << "X.GetBase():   " << X.GetBase() << endl;
	cout << "X.Get()    :   " << X.Get()     << endl;
	Derived Y(12,25);
	cout << "執行 「Derived Y(12,25)」 之後: " << endl;
	cout << "Y.GetBase():   " << Y.GetBase()  << endl;
	cout << "Y.Get()    :   " << Y.Get()      << endl;
	system("pause");
	return 0;
}
