// CompClass2.h
// --------------------------------------
#ifndef COMPCLASS2_H
#define COMPCLASS2_H
#include <iostream>
using namespace std;

//---- 摸 Component --------
class Component
{
  private:
    int I;
  public:
    // 摸 Component 篶ㄧ计
    Component (): I(1)
     {cout << "㊣ Component 箇砞篶ㄧ计" << endl; }
    Component (int N): I(N)
     {cout << "㊣ Component 篶ㄧ计" << endl;}
    // 摸 Component 秆篶ㄧ计
    ~Component()
     {cout << "㊣ Component 秆篶ㄧ计" << endl;}
    int Get() const   {return I;}
    void Double()     {I*=2;}
};

//---- 摸 Host --------
class Host
{
  private:
    int k;
    Component C1, C2;
  public:
    Component C3;
    // 摸 Host 篶ㄧ计
    Host() : k(1), C1(1), C2(1), C3(1)
    {cout << "㊣ Host 箇砞篶ㄧ计" << endl; }
    Host(int L, int M, int N, int P) : k(L), C1(M), C2(N), C3(P)
    {cout << "㊣ Host 篶ㄧ计" << endl; }
    // 摸 Host 秆篶ㄧ计
    ~Host() {cout << "㊣ Host 秆篶ㄧ计" << endl;} 
    int  Get() const  {return k;}
    void Double()     {k*=2;}
    void DoubleComp() {C1.Double(); C2.Double(); C3.Double();}
    int  GetC1()      {return C1.Get();}
    int  GetC2()      {return C2.Get();}
};

#endif