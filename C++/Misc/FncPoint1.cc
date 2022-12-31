// FncPoint.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// --- ㄧ计 F1() F2()㎝Twice()  --
double F1(int);
double F2(int);
double Twice(double (*)(int), int);

// --- 祘Α ---------------------------
int main()
{
	int A = 3;
	int B = 5;

	cout  << "Twice(F1, A)琌: "
		  <<  Twice(F1, A) << endl;
	cout  << "Twice(F2, B)琌: "
		  <<  Twice(F2, B) << endl;   
	system ("pause");
	return 0 ;
}

// ---- ㄧ计F1()﹚竡 ---------------------
double F1(int N)
{ 
	return double (N*N);
}

// ---- ㄧ计F2()﹚竡 ---------------------
double F2(int N)
{ 
	return double (N*N*N);
}

// ---  ㄧ计Twice()﹚竡 ------------------
double Twice(double (*pF)(int), int N)
{
	return 2.0*double(pF(N));
}
