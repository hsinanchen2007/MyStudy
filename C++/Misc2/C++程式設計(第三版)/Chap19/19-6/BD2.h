// B&D2.h
// --------------------------------------
#ifndef BD2_H
#define BD2_H
#include <iostream>
using namespace std;

//---- 摸 Base --------
class Base
{
 private:
   int i;
 public:
   Base():  i(3)
     {cout << "㊣ Base 箇砞篶ㄧ计" << endl; }
   Base(int N): i(N)
     {cout << "㊣ Base 篶ㄧ计" << endl; }
   ~Base()
     {cout << "㊣ Base 秆篶ㄧ计" << endl;}
   void Set(int N)  {i=N;}
   int  Get() const {return i;}
   void Double()    {i*=2;}
   void Triple()    {i*=3;}
};

//---- 摸 Derived --------
class Derived : public Base
{
 private:
   int i;
 public:
   Derived(): i(5)
     {cout << "㊣ Derived 箇砞篶ㄧ计" << endl; }
   Derived(int M, int N) : Base(M), i(N)
     {cout << "㊣ Derived 篶ㄧ计" << endl; }
   ~Derived()
     {cout << "㊣ Derived 秆篶ㄧ计" << endl;}
   void Set(int N)      {i=N;}
   void SetBase(int N)  {Base::Set(N);}
   void Double()    {i*=2;}
   int  Get()     const {return i;}
   int  GetBase() const {return Base::Get();}
};
#endif