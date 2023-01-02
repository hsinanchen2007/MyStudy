// Complex.h
// --------------------------------------
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

// class declaration
class Complex
{
	friend void  Display(const Complex&);
	friend inline float Abs    (const Complex&);
	friend inline float Ang    (const Complex&);
	friend inline float Real   (const Complex&);
	friend inline float Imag   (const Complex&);
	private:
		float *Z;
	public:
    // 建構函數
    Complex(float = 0.0, float = 0.0);
    // 宣告複製建構函數
    Complex(const Complex&);
    // 解構函數
    ~Complex();
    // 宣告指派運算子 operator = ()
    Complex&  operator =  (const Complex&);
    // 宣告加法運算子 operator + ()
    inline Complex  operator +  (const Complex&);
    // 宣告乘法運算子 operator * ()
    inline Complex  operator *  (const Complex&);
    // 宣告除法運算子 operator / ()
    Complex  operator /  (const Complex&);
};

// 解構函數的定義
Complex::~Complex()
 {delete [] Z; cout << "呼叫解構函數"<< endl;}

// 建構函數的定義
Complex::Complex(float x, float y) 
{
  Z= new float [2];
  Z[0]=x;
  Z[1]=y;
  return;
}

// 複製建構函數的定義
Complex::Complex(const Complex& OldZ)
{
  Z = new float [2];
  for (int i=0; i<2; i++)
   Z[i]= OldZ.Z[i];
  return;
}

// 定義指派運算子 operator = ()
Complex& Complex::operator=(const Complex& Z2)
{
  for (int i=0; i<2; i++)
       Z[i] = Z2.Z[i];
  return *this;
}

// 定義加法運算子 operator + ()
Complex Complex::operator+(const Complex& Z2)
{
  return Complex(Z[0]+Z2.Z[0], Z[1]+Z2.Z[1]);
}

// 定義乘法運算子 operator * ()
Complex Complex::operator*(const Complex& Z2)
{
  return Complex (Z[0]*Z2.Z[0]-Z[1]*Z2.Z[1],
                  Z[0]*Z2.Z[1]+Z[1]*Z2.Z[0]);
}

// 定義除法運算子 operator / ()
Complex Complex::operator/(const Complex & Z2)
{
  Complex Z1(Z[0],Z[1]);
  float r , im , Z1_r , Z1_im , Temp ;
  r=Z2.Z[0];
  im=Z2.Z[1];
  Temp = r*r+im*im;
  Z1_r=Z1.Z[0] ; Z1_im=Z1.Z[1] ;
  return Complex ((Z1_r*r+Z1_im*im)/Temp,
                  (Z1_im*r-Z1_r*im)/Temp );
}

// 定義 friend 函數 Display()
void Display(const Complex& Z1)
{
  float f, a;
  char Sign;
  f=Imag(Z1);
  if (f>=0) Sign= '+'; else Sign='-';
  cout << setw(10)
       << setiosflags(ios::fixed)
       << setiosflags(ios::right)
       << setiosflags(ios::showpoint)
       << setprecision(5)
       << Z1.Z[0] << " " << Sign << " j " 
       << fabs(f) << endl;
  return;
}

// 定義 friend 函數 Abs()
float Abs(const Complex& Z1)
 {return sqrt(Z1.Z[0]*Z1.Z[0]+Z1.Z[1]*Z1.Z[1]);}

// 定義 friend 函數 Ang()
float Ang(const Complex& Z1)
 {return atan2( Imag( Z1 ) , Real( Z1 ) );}

// 定義 friend 函數 Real()
float Real(const Complex& Z1)
 { return Z1.Z[0];}

// 定義 friend 函數 Imag()
float Imag(const Complex& Z1)
 { return Z1.Z[1];}

// 定義 friend 函數 DisplayPhasor()
void DisplayPhasor(const Complex& Z1)
{
  float f, a;
  char Sign;
  cout << "In Phasor form:\n";
  cout 
   << setw(10)
   << setiosflags(ios::fixed)
   << setiosflags(ios::right)
   << setiosflags(ios::showpoint)
   << setprecision(5)
   << Abs(Z1) << " phase " << Ang(Z1) << endl;
  return;
}
#endif