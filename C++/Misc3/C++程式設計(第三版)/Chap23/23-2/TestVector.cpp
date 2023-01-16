// TestVector.cpp
// --------------------------------------
#include "Vector.h"

int main ()
{
	double Ddata1[]={2, 0.5, 4.6};
	double Ddata2[]={4, 6.5, 3.8};
	int    Idata1[]={2, 5, 6};
	int    Idata2[]={4, 65, 38};
	Vector<double> DV1(3, Ddata1);
	Vector<double> DV2(3, Ddata2), DVa(3), DVb(3);
	Vector<int>    IV1(3, Idata1);
	Vector<int>    IV2(3, Idata2), IVa(3), IVb(3);
	int Idot;
	double Ddot;

	cout << "\n---------------------" << endl;
	cout << "���� Vector<double>:   " << endl;
	cout << " DV1 ���ȬO:    "        << endl;
	DV1.Display();
	cout << " DV2 ���ȬO:    "        << endl;
	DV2.Display();
	DVa=DV1+DV2;
	cout << " (DV1 + DV2) ���ȬO:"    << endl;
	DVa.Display();
	DVb=DV1/2.0;
	cout << " (DV1/2.0)   ���ȬO:  "    << endl;
	cout << "      "  << DVb[1]
			<< "      "  << DVb[2]
			<< "      "  << DVb[3]       << endl;
	Ddot = DV1*DV2;
	cout << " DV1 �M DV2  �����n�O :    "
			<< Ddot << endl;
	cout << "\n-------------------- " << endl;
	cout << "���� Vector<int>: "      << endl;
	cout << " IV1 ���ȬO: "           << endl;
	IV1.Display();
	cout << " IV2 ���ȬO: "           << endl;
	IV2.Display();
	IVa=IV1+IV2;
	cout << " (IV1 + IV2)���ȬO:"     << endl;
	IVa.Display();
	IVb=IV1/2.0;
	cout << " (IV1/2.0)  ���ȬO:"     << endl;
	IVb.Display();
	Idot = IV1*IV2;
	cout << " IV1 �M IV2 �����n�O  :    "
			<< Idot << endl;
	system("pause");
	return 0;
}
