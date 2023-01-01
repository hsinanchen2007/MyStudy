// FncPoint.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// --- ��� F1()�A F2()�MTwice() ���ŧi --
double F1(int);
double F2(int);
double Twice(double (*)(int), int);

// --- �D�{�� ---------------------------
int main()
{
	int A = 3;
	int B = 5;

	cout  << "Twice(F1, A)���ȬO: "
		  <<  Twice(F1, A) << endl;
	cout  << "Twice(F2, B)���ȬO: "
		  <<  Twice(F2, B) << endl;   
	system ("pause");
	return 0 ;
}

// ---- ���F1()���w�q ---------------------
double F1(int N)
{ 
	return double (N*N);
}

// ---- ���F2()���w�q ---------------------
double F2(int N)
{ 
	return double (N*N*N);
}

// ---  ���Twice()���w�q ------------------
double Twice(double (*pF)(int), int N)
{
	return 2.0*double(pF(N));
}
