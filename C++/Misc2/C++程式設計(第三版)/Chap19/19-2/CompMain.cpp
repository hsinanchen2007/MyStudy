// CompMain.cpp

#include "CompClass.h"

int main()
{
	Host H(1,2,3,4);
	cout << "���� �uHost H(1,2,3,4)�v����: " << endl;
	cout << "H.Get()   = " << H.Get()   << endl;
	cout << "H.GetC1() = " << H.GetC1() << endl;
	cout << "H.GetC2() = " << H.GetC2() << endl;
	cout << "H.C3.Get()= " << H.C3.Get()<< endl;
	H.Double();
	cout << "���� �uH.Double()�v     ����: " << endl;
	cout << "H.Get()   = " << H.Get()   << endl;
	cout << "H.GetC1() = " << H.GetC1() << endl;
	cout << "H.GetC2() = " << H.GetC2() << endl;
	cout << "H.C3.Get()= " << H.C3.Get()<< endl;
	H.DoubleComp();
	cout << "���� �uH.DoubleComp()�v ����: " << endl;
	cout << "H.Get()   = " << H.Get()   << endl;
	cout << "H.GetC1() = " << H.GetC1() << endl;
	cout << "H.GetC2() = " << H.GetC2() << endl;
	cout << "H.C3.Get()= " << H.C3.Get()<< endl;
	system("pause");
	return 0;
}