// Check.cpp
// --------------------------------------
#include <iostream>
using namespace std;

namespace         // ���R�W���W�٪Ŷ�
{
	double GainL=5.6;          // GainL �Q����
	double FncA(double x)    // FncA() �Q����
		{return x*GainL;}
}
double GainG = 3.8;		      // ����`�� GainG
double FncB(double);	          // FncB() ���쫬

// ----�D�{��-----------------------
int main()
{
	cout << "FncA(5)�O: "
			<< FncA(5) << endl;   //  �I�s FncA()
	cout << "FncB(5)�O: "
			<< FncB(5) << endl;   //  �I�s FncB()
   system("PAUSE");
   return 0;
}
