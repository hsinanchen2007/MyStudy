// TestF2.cpp
// --------------------------------------
#include "FloatNM.h"
int main()
{
	Float f1(2.4), f2(3.5);
	cout << "f1    : " << f1    << endl;
	cout << "f2    : " << f2    << endl;
	cout << "f1+f2 : " << f1+f2 << endl;
	cout << "f1*f2 : " << f1*f2 << endl;
	cout << "f1^3.2: " << (f1^3.2) << endl;
	cout << "f1+=f2: " << (f1+=f2) << endl;
	system("PAUSE");
	return 0;
}
