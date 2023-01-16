// MacroTest.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// -- �������O ---------------------------
#define MAX(x,y) ((x) > (y) ?  (x) : (y))
#define PRODUCT(x,y) ((x) * (y))
#define Merge(x, y) x##y 
#define ShowValue(x)                                     \
{                                                                       \
	cerr << #x << " ���ȬO: " << x << endl;    \
	cerr << "�� Enter ���~��." << endl;           \
	cin.get();                                                        \
} 	

// ---- �D�{�� -------------------------------------
int main()
{
	int a = 3, b = 9;
	double F1= 12.5, F2=8.38;
	cout << "MAX(a, b)   = " << MAX(a, b) << endl;
	cout << "MAX(F1, F2) = " << MAX(F1, F2) << endl;
	cout << "PRODUCT(F1, F2) = " 
		    << PRODUCT(F1+2, F2+6)  << endl;
	ShowValue(F1);
	cout << "\n���� Merge(F,2) �����G�O: " << Merge(F,2) << endl;  
	system("PAUSE");
	return 0;
}