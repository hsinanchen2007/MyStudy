// TestVM.cpp
#include "Vector.h"
#include "Matrix.h"
#include <iostream>

using namespace std;
int main ()
{
	double W1[]={2.1, 0.5, 3.2, 6.4, 8.2, 4.9};
	double W2[]={4.6, 6.5, 3.6, 4.2, 5.8, 9.4};
	double W3[]={2.1, 3.2, 9.8, 6.9, 2.4, 1.6};
	double w1[]={2, 0.5};
	double w2[]={4, 6.5};
	Matrix<double> M1(2,3, W1);
	Matrix<double> M2(2,3, W2);
	Matrix<double> M3(3,2, W3);
	Matrix<double> Ma(2,3), Mb(2,2);
	Vector<double> V1(2, w1);
	Vector<double> V2(2, w2), Xa(3), Xb(3);

	cout << " M1 �O:  "  << endl;
	M1.Display();
	cout << " M2 �O:  "  << endl;
	M2.Display();
	cout << " M3 �O:  "  << endl;
	M3.Display();
	Ma=M1+M2;
	cout << "(M1+M2) �O  :  "  << endl;
	Ma.Display();
	Mb=M1*M3;
	cout << "(M1*M3) �O  :  "  << endl;
	Mb.Display();
	V2 = M1.PickCol(2);
	cout << " M1 ����2��O:  " << endl;
	V2.Display();
	cout << " V1 �O:  "  << endl;
	V1.Display();
	M1.SetCol(3,V1);
	cout << " �N M1 ����3��]�� V1 ��\n"
		<< " M1 �ܦ���:  " << endl;
	M1.Display();
	system("pause");
	return 0;
}
