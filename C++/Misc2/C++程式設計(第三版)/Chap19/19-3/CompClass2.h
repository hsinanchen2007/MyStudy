// CompClass2.h
// --------------------------------------
#ifndef COMPCLASS2_H
#define COMPCLASS2_H
#include <iostream>
using namespace std;

//---- �ŧi���O Component --------
class Component
{
  private:
    int I;
  public:
    // ���O Component ���غc���
    Component (): I(1)
     {cout << "�I�s Component �w�]�غc���" << endl; }
    Component (int N): I(N)
     {cout << "�I�s Component �غc���" << endl;}
    // ���O Component ���Ѻc���
    ~Component()
     {cout << "�I�s Component �Ѻc���" << endl;}
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
    Host() : k(1), C1(1), C2(1), C3(1)
    {cout << "�I�s Host �w�]�غc���" << endl; }
    Host(int L, int M, int N, int P) : k(L), C1(M), C2(N), C3(P)
    {cout << "�I�s Host �غc���" << endl; }
    // ���O Host ���Ѻc���
    ~Host() {cout << "�I�s Host �Ѻc���" << endl;} 
    int  Get() const  {return k;}
    void Double()     {k*=2;}
    void DoubleComp() {C1.Double(); C2.Double(); C3.Double();}
    int  GetC1()      {return C1.Get();}
    int  GetC2()      {return C2.Get();}
};

#endif