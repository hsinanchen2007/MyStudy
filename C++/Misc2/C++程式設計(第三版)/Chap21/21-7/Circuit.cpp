// Circuit.cpp
// --------------------------------------
#include "Complex.h"
int main()
{ 
	float Omega=1.0e4, C=10e-6, L=0.01;
	Complex ZC(0, -1/(Omega*C));
	Complex ZL(0,Omega*L);
	Complex R1(100,0),R2(50,0);
	Complex Zeq;
	cout << "Zeq:" << endl;
	Zeq=(R1+ZL)+(R2||ZC);
	Display(Zeq);
	DisplayPhasor(Zeq);
	system("PAUSE");
	return 0;
}
