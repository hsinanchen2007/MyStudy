// SwapV.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
// ---ㄧ计--------------------
void DisplayV1(double*, int);
void DisplayV2(double*, int);
void Swap(double** x, double** y);
// ---祘Α------------------------
int main()
{
	const int SizeA = 5;
	const int SizeB = 7;
	double* A = new double [SizeA];
	double* B = new double [SizeB];

	for (int i=0; i<SizeA; i++)
		A[i]= 1.0*i;
	for (int i=0; i<SizeB; i++)
		B[i]= 3.0*i;

	cout << "磅︽ Swap() 玡, \n";
	cout << "A 琌 :\n";
	DisplayV1(A, SizeA);
	cout << "B 琌 :\n";
	DisplayV2(B, SizeB);

	Swap(&A,&B);

	cout << "磅︽ Swap() , \n";
	cout << "A 琌 :\n";
	DisplayV1(A, SizeB);
	cout << "B 琌 :\n";
	DisplayV2(B, SizeA);

	delete [] A;
	delete B;
	system ("pause");
	return 0;
}

// ------ ㄧ计DisplayV1()﹚竡 -------------
void DisplayV1(double* V, int N)
{
	cout << endl;
	for(int i = 0; i < N; i++)
		cout << setw(5) << V[i] << " ";
	cout << endl;
	return;
}
// ------- ㄧ计DisplayV2()﹚竡 -------------
void DisplayV2(double* V, int N)
{
	cout << endl;
	for(int i = 0; i < N; i++)
		cout << setw(5) << *(V+i) << " ";
	cout << endl;
	return;
}
// -------- ㄧ计Swap()﹚竡 -----------------
void Swap(double** x, double** y)
{
	double* Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
}
