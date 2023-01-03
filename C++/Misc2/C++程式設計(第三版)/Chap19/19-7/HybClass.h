// HybClass.h
// --------------------------------------
#ifndef HYBCLASS_H
#define HYBCLASS_H
#include <iostream>
using namespace std;

//---- �ŧi���O Component --------
class Component
{
private:
	int i;
public:
	Component ():  i(1)
	{
		cout	<< "�I�s Component �w�]�غc���"
				<< endl; 
	}
	Component (int N) : i(N)
	{	
		cout	<< "�I�s Component �غc���"
				<< endl; 
	}
	~Component()
	{
		cout	<< "�I�s Component �Ѻc���"
				<< endl;}
	int Get() const   {return i;}
	void Double()     {i*=2;}
};

//---- �ŧi���O Base --------
class Base
{
private:
	int j;
public:
	Base(): j(3)
	{
		cout	<< "�I�s Base �w�]�غc���"
				<< endl; 
	}
	Base(int N): j(N)
	{
		cout	<< "�I�s Base �غc���"
				<< endl; 
	}
	~Base()
	{
		cout	<< "�I�s Base �Ѻc���"
				<< endl;
	}
	void Set(int N)  {j=N;}
	int  Get() const {return j;}
	void Double()    {j*=2;}
	void Triple()    {j*=3;}
};

//---- �ŧi���O Hybrid --------
class Hybrid : public Base
{
private:
	int k;
	Component C1, C2;
public:
	Hybrid() : k(1), C1(3), C2(4), Base(2)
	{
		cout	<< "�I�s Hybrid �w�]�غc���"
				<< endl; 
	}
	Hybrid(int L, int M, int N, int P)
		: k(L), Base(M), C1(N), C2(P)
	{
		cout << "�I�s Hybrid �غc���"	<< endl; 
	}
	~Hybrid()
	{
		cout << "�I�s Hybrid �Ѻc���"	<< endl;
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