// CompClass.h
// --------------------------------------
#ifndef COMPCLASS_H
#define COMPCLASS_H
#include <iostream>
using namespace std;

//---- �ŧi���O Component --------
class Component
{
	private:
		int I;
	public:
	// ���O Component ���غc���
		Component (): I(1)      {}     // �w�]�غc���
		Component (int N): I(N) {} // �غc���
    // ���O Component ���Ѻc���
		~Component()            {}
		int Get() const   {return I;}
		void Double()     {I*=2;}
};

//---- �ŧi���O Host --------
class Host
{
	private:
		int k;
		Component C1, C2;
	public:
		Component C3;
    // ���O Host ���غc���
		Host() : k(1), C1(1), C2(1), C3(1)  {}
		Host(int L, int M, int N, int P)
				: k(L), C1(M), C2(N), C3(P)  {}
    // ���O Host ���Ѻc���
		~Host()           {}
		int  Get() const  {return k;}
		void Double()     {k*=2;}
		void DoubleComp()
			{C1.Double(); C2.Double(); C3.Double();}
		int  GetC1()      {return C1.Get();}
		int  GetC2()      {return C2.Get();}
};

#endif