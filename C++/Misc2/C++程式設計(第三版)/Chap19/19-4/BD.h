// BD.h
// --------------------------------------
#ifndef BD_H
#define BD_H
#include <iostream>
using namespace std;

//---- 宣告類別 Base --------
class Base
{
 private:
   int i;
 public:
   Base():  i(3)    {}
   Base(int N): i(N){}
   ~Base()   {}
   void Set(int N)  {i=N;}
   int  Get() const {return i;}
   void Double()    {i*=2;}
   void Triple()    {i*=3;}
};

//---- 宣告類別 Derived --------
class Derived : public Base
{
 private:
   int i;
 public:
   Derived(): i(5)      {}
   Derived(int M, int N) : Base(M), i(N) {}
   ~Derived()  {}
   void Set(int N)      {i=N;}
   void SetBase(int N)  {Base::Set(N);}
   void Double()    {i*=2;}
   int  Get()     const {return i;}
   int  GetBase() const {return Base::Get();}
};
#endif