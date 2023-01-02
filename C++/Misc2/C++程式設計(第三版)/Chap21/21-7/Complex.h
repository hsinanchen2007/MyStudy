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
    // �غc���
    Complex(float = 0.0, float = 0.0);
    // �ŧi�ƻs�غc���
    Complex(const Complex&);
    // �Ѻc���
    ~Complex();
    // �ŧi�����B��l operator = ()
    Complex&  operator =  (const Complex&);
    // �ŧi�[�k�B��l operator + ()
    inline Complex  operator +  (const Complex&);
    // �ŧi���k�B��l operator * ()
    inline Complex  operator *  (const Complex&);
    // �ŧi���k�B��l operator / ()
    Complex  operator /  (const Complex&);
    // �ŧi���p�B��l operator || ()
    Complex operator ||(const Complex &); 
};

// �Ѻc��ƪ��w�q
Complex::~Complex()
{delete [] Z;}

// �غc��ƪ��w�q
Complex::Complex(float x, float y) 
{
	Z= new float [2];
	Z[0]=x;
	Z[1]=y;
	return;
}

// �ƻs�غc��ƪ��w�q
Complex::Complex(const Complex& OldZ)
{
	Z = new float [2];
	for (int i=0; i<2; i++)
		Z[i]= OldZ.Z[i];
	return;
}

// �w�q�����B��l operator = ()
Complex& Complex::operator=(const Complex& Z2)
{
	for (int i=0; i<2; i++)
		Z[i] = Z2.Z[i];
	return *this;
}

// �w�q�[�k�B��l operator + ()
Complex Complex::operator+(const Complex& Z2)
{
	return Complex(Z[0]+Z2.Z[0], Z[1]+Z2.Z[1]);
}

// �w�q���k�B��l operator * ()
Complex Complex::operator*(const Complex& Z2)
{
	return Complex (Z[0]*Z2.Z[0]-Z[1]*Z2.Z[1],Z[0]*Z2.Z[1]+Z[1]*Z2.Z[0]);                
}

// �w�q���k�B��l operator / ()
Complex Complex::operator/(const Complex & Z2)
{
	Complex Z1(Z[0],Z[1]);
	float r , im , Z1_r , Z1_im , Temp ;
	r=Z2.Z[0];
	im=Z2.Z[1];
	Temp = r*r+im*im;
	Z1_r=Z1.Z[0] ; Z1_im=Z1.Z[1] ;
	return Complex ((Z1_r*r+Z1_im*im)/Temp, (Z1_im*r-Z1_r*im)/Temp );               
}

// �w�q���p�B��l operator || ()
Complex Complex::operator||(const Complex & Z2)
{
	Complex Z1(Z[0],Z[1]);
	return (Z1*Z2)/(Z1+Z2);
}

// �w�q friend ��� Display()
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

// �w�q friend ��� Abs()
float Abs(const Complex& Z1)
	{return sqrt(Z1.Z[0]*Z1.Z[0]+Z1.Z[1]*Z1.Z[1]);}

// �w�q friend ��� Ang()
float Ang(const Complex& Z1)
	{return atan2( Imag( Z1 ) , Real( Z1 ) );}

// �w�q friend ��� Real()
float Real(const Complex& Z1)
	{return Z1.Z[0];}

// �w�q friend ��� Imag()
float Imag(const Complex& Z1)
	{return Z1.Z[1];}

// �w�q friend ��� DisplayPhasor()
void DisplayPhasor(const Complex& Z1)
{
	float f, a;
	char Sign;
	cout << "In Phasor form:\n";
	cout << setw(10)
			<< setiosflags(ios::fixed)
			<< setiosflags(ios::right)
			<< setiosflags(ios::showpoint)
			<< setprecision(5)
			<< Abs(Z1) << " phase " << Ang(Z1) << endl;
	return;
}

#endif