// TestComplex
// --------------------------------------
#include "Complex.h"
int main()
{ 
	if (1) 
	{
		float x1=3.5, y1=1.8;
		float x2=2.6, y2=7.2;
		Complex Z1(x1, y1);
		Complex Z2(x2, y2);
		Complex A;
		cout << "Z1   : ";
		Display(Z1);
		cout << "Z2   : ";
		Display(Z2);
		cout << "Z1+Z2: ";
		Display(Z1+Z2);
		cout << "Z1*Z2: ";
		Display(Z1*Z2);
		cout << "(1) ";
		Display(Z1/Z2);
		cout << "(2) ";
		A = Z1/Z2;
		cout << "(3) ";
		DisplayPhasor(A);
	}
	system("PAUSE");
	return 0;
}