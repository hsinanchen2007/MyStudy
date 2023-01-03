// B&D2.h
// --------------------------------------
#ifndef BD2_H
#define BD2_H
#include <iostream>
using namespace std;

//---- �ŧi���O Base --------
class Base
{
 private:
   int i;
 public:
   Base():  i(3)
     {cout << "�I�s Base �w�]�غc���" << endl; }
   Base(int N): i(N)
     {cout << "�I�s Base �غc���" << endl; }
   ~Base()
     {cout << "�I�s Base �Ѻc���" << endl;}
   void Set(int N)  {i=N;}
   int  Get() const {return i;}
   void Double()    {i*=2;}
   void Triple()    {i*=3;}
};

//---- �ŧi���O Derived --------
class Derived : public Base
{
 private:
   int i;
 public:
   Derived(): i(5)
     {cout << "�I�s Derived �w�]�غc���" << endl; }
   Derived(int M, int N) : Base(M), i(N)
     {cout << "�I�s Derived �غc���" << endl; }
   ~Derived()
     {cout << "�I�s Derived �Ѻc���" << endl;}
   void Set(int N)      {i=N;}
   void SetBase(int N)  {Base::Set(N);}
   void Double()    {i*=2;}
   int  Get()     const {return i;}
   int  GetBase() const {return Base::Get();}
};
#endif