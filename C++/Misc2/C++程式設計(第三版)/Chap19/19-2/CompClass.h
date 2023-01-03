// CompClass.h
// --------------------------------------
#ifndef COMPCLASS_H
#define COMPCLASS_H
#include <iostream>
using namespace std;

//---- 宣告類別 Component --------
class Component
{
	private:
		int I;
	public:
	// 類別 Component 的建構函數
		Component (): I(1)      {}     // 預設建構函數
		Component (int N): I(N) {} // 建構函數
    // 類別 Component 的解構函數
		~Component()            {}
		int Get() const   {return I;}
		void Double()     {I*=2;}
};

//---- 宣告類別 Host --------
class Host
{
	private:
		int k;
		Component C1, C2;
	public:
		Component C3;
    // 類別 Host 的建構函數
		Host() : k(1), C1(1), C2(1), C3(1)  {}
		Host(int L, int M, int N, int P)
				: k(L), C1(M), C2(N), C3(P)  {}
    // 類別 Host 的解構函數
		~Host()           {}
		int  Get() const  {return k;}
		void Double()     {k*=2;}
		void DoubleComp()
			{C1.Double(); C2.Double(); C3.Double();}
		int  GetC1()      {return C1.Get();}
		int  GetC2()      {return C2.Get();}
};

#endif