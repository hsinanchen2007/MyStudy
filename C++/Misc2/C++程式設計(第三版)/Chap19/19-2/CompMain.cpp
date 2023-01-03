// CompMain.cpp

#include "CompClass.h"

int main()
{
	Host H(1,2,3,4);
	cout << "執行 「Host H(1,2,3,4)」之後: " << endl;
	cout << "H.Get()   = " << H.Get()   << endl;
	cout << "H.GetC1() = " << H.GetC1() << endl;
	cout << "H.GetC2() = " << H.GetC2() << endl;
	cout << "H.C3.Get()= " << H.C3.Get()<< endl;
	H.Double();
	cout << "執行 「H.Double()」     之後: " << endl;
	cout << "H.Get()   = " << H.Get()   << endl;
	cout << "H.GetC1() = " << H.GetC1() << endl;
	cout << "H.GetC2() = " << H.GetC2() << endl;
	cout << "H.C3.Get()= " << H.C3.Get()<< endl;
	H.DoubleComp();
	cout << "執行 「H.DoubleComp()」 之後: " << endl;
	cout << "H.Get()   = " << H.Get()   << endl;
	cout << "H.GetC1() = " << H.GetC1() << endl;
	cout << "H.GetC2() = " << H.GetC2() << endl;
	cout << "H.C3.Get()= " << H.C3.Get()<< endl;
	system("pause");
	return 0;
}