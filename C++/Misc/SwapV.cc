// SwapV.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
// ---��ƪ��ŧi--------------------
void DisplayV1(double*, int);
void DisplayV2(double*, int);
void Swap(double** x, double** y);
// ---�D�{��------------------------
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

	cout << "���� Swap() �e, \n";
	cout << "A �O :\n";
	DisplayV1(A, SizeA);
	cout << "B �O :\n";
	DisplayV2(B, SizeB);

	Swap(&A,&B);

	cout << "���� Swap() ��, \n";
	cout << "A �O :\n";
	DisplayV1(A, SizeB);
	cout << "B �O :\n";
	DisplayV2(B, SizeA);

	delete [] A;
	delete B;
	system ("pause");
	return 0;
}

// ------ ���DisplayV1()���w�q -------------
void DisplayV1(double* V, int N)
{
	cout << endl;
	for(int i = 0; i < N; i++)
		cout << setw(5) << V[i] << " ";
	cout << endl;
	return;
}
// ------- ���DisplayV2()���w�q -------------
void DisplayV2(double* V, int N)
{
	cout << endl;
	for(int i = 0; i < N; i++)
		cout << setw(5) << *(V+i) << " ";
	cout << endl;
	return;
}
// -------- ���Swap()���w�q -----------------
void Swap(double** x, double** y)
{
	double* Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
}
