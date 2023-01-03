// HybClass.h
// --------------------------------------
#ifndef HYBCLASS_H
#define HYBCLASS_H
#include <iostream>
using namespace std;

//---- 摸 Component --------
class Component
{
private:
	int i;
public:
	Component ():  i(1)
	{
		cout	<< "㊣ Component 箇砞篶ㄧ计"
				<< endl; 
	}
	Component (int N) : i(N)
	{	
		cout	<< "㊣ Component 篶ㄧ计"
				<< endl; 
	}
	~Component()
	{
		cout	<< "㊣ Component 秆篶ㄧ计"
				<< endl;}
	int Get() const   {return i;}
	void Double()     {i*=2;}
};

//---- 摸 Base --------
class Base
{
private:
	int j;
public:
	Base(): j(3)
	{
		cout	<< "㊣ Base 箇砞篶ㄧ计"
				<< endl; 
	}
	Base(int N): j(N)
	{
		cout	<< "㊣ Base 篶ㄧ计"
				<< endl; 
	}
	~Base()
	{
		cout	<< "㊣ Base 秆篶ㄧ计"
				<< endl;
	}
	void Set(int N)  {j=N;}
	int  Get() const {return j;}
	void Double()    {j*=2;}
	void Triple()    {j*=3;}
};

//---- 摸 Hybrid --------
class Hybrid : public Base
{
private:
	int k;
	Component C1, C2;
public:
	Hybrid() : k(1), C1(3), C2(4), Base(2)
	{
		cout	<< "㊣ Hybrid 箇砞篶ㄧ计"
				<< endl; 
	}
	Hybrid(int L, int M, int N, int P)
		: k(L), Base(M), C1(N), C2(P)
	{
		cout << "㊣ Hybrid 篶ㄧ计"	<< endl; 
	}
	~Hybrid()
	{
		cout << "㊣ Hybrid 秆篶ㄧ计"	<< endl;
	}
	int Get() const   {return k;}
	void Double()     {k*=2;}
	void DoubleBase() {Base::Double();}
	void DoubleComp() {C1.Double(); C2.Double();}
	int GetBase()     {return Base::Get();}
	int GetC1()       {return C1.Get();}
	int GetC2()       {return C2.Get();}
};
#endif	