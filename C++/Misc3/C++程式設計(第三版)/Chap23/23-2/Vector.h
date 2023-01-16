// Vector.h
#ifndef Vector_H
#define Vector_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

inline void Check(bool ErrorCondition,
				  const string& Message = "Requirement failed")
{
	if (ErrorCondition)
	{ cerr << Message << endl; exit(1); }
}

// Vector �˪����O
template <class T>
class Vector
{
	// �ŧi���k�B��l-1 operator * ()
	friend Vector<T> operator*(const T& , const Vector<T>& );    // Z3=f*Z2;
	// �ŧi���k�B��l-2 operator * ()
	friend Vector<T> operator*(const Vector<T>& , const T& );
private:
	int Size;
	T* V;
	inline void Create(int);
public:
	// �ŧi�غc���
	Vector(int);
	Vector(int, const T*);
	// �ŧi�ƻs�غc���
	Vector(Vector<T>&);
	// �ŧi�Ѻc���
	~Vector();
	// Operators
	// �ŧi�����B��l operator = ()
	Vector<T> operator=(const Vector<T>&);
	// �ŧi�[�k�B��l operator + ()
	Vector<T> operator+(const Vector<T>&);
	// �ŧi��k�B��l operator - ()
	Vector<T> operator-(const Vector<T>&);
	// �ŧi���k�B��l-3 operator * ()
	T operator*(const Vector<T>&);
	// �ŧi���k�B��l operator / ()
	Vector<T> operator/(const T&);
	// �ŧi���޹B��l operator [] ()
	T& operator[](int i)
	{
		Check(i>Size, "���޿��~, �W�L���!");
		return V[i];
	}
	// �ŧi������� Display()
	void Display();
};

// class implementation
// ��� Create() ���w�q
template <class T>
void Vector<T>::Create(int N)
{
	if(N<1)
	{Size = 0; V = 0;}
	else
	{Size = N; V= new T[N+1];}
}

// �غc��ƪ��w�q
template <class T>
Vector<T>::Vector(int N)
{
	Create(N);
	return;
}

// �Ѻc��ƪ��w�q
template <class T>
Vector<T>::~Vector()  { delete [] V; }

// �ƻs�غc��ƪ��w�q-1
template <class T>
Vector<T>::Vector(int N, const T* OldV)
{
	Create(N);
	for (int i=1; i<= Size; i++)
		V[i]= OldV[i-1];
	return;
}

// �ƻs�غc��ƪ��w�q-2
template <class T>
Vector<T>::Vector(Vector<T>& OldV)
{
	Create(OldV.Size);
	for (int i=1; i<= Size; i++)
		V[i]= OldV.V[i];
	return;
}

// �w�q�����B��l operator = ()
template <class T>
Vector<T> Vector<T>::operator=(const Vector<T>& V2)
{
	if (Size!=V2.Size)
		Create(V2.Size);
	for (int i=1; i<= Size; i++)
		V[i] = V2.V[i];
	return *this;
}

// �w�q�[�k�B��l operator + ()
template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>& V2)
{
	Check(Size!=V2.Size,
		"�[�k�B����~, ���פ��ۦP!");
	Vector<T> Temp(Size);
	for (int i=1; i<= Size; i++)
		Temp.V[i]= V[i]+V2.V[i];
	return Temp;
}

// �w�q��k�B��l operator - ()
template <class T>
Vector<T> Vector<T>::operator-(const Vector<T>& V2)
{
	Check(Size!=V2.Size,
		"��k�B����~, ���פ��ۦP!");
	Vector<T> Temp(Size);
	for (int i=1; i<= Size; i++)
		Temp.V[i]= V[i]-V2.V[i];
	return Temp;
}


// �w�q���k�B��l-1  operator * ()
template <class T>
Vector<T> operator*(const T& f, const Vector<T>& V1)
{
	Vector<T> Temp(V1.Size);
	for(int i=1; i<=V1.Size; i++)
		Temp.V[i] = f * V1.V[i];
	return Temp;
}

// �w�q���k�B��l-2  operator * ()
template <class T>
Vector<T> operator*(const Vector<T>& V1, const T& f)
{
	Vector<T> Temp(V1.Size);
	for(int i=1; i<=V1.Size; i++)
		Temp.V[i] = f * V1.V[i];
	return Temp;
}

// �w�q���k�B��l-3 operator * ()
template <class T>
T Vector<T>::operator*(const Vector<T>& V2)
{
	Check(Size!=V2.Size,
		"���n�B����~, ���פ��ۦP!");
	T Product = 0;
	for (int i=1; i<= Size; i++)
		Product += V[i]*V2.V[i];
	return Product;
}

// �w�q������� Display()
template <class T>
void Vector<T>::Display()
{
	for(int i = 1; i <= Size; i++)
		cout << setiosflags(ios::right)
				<< setiosflags(ios::fixed)
				<< setiosflags(ios::showpoint)
				<< setprecision(4)
				<< setw(12) << V[i];
	cout << endl;
	return;
}

// �w�q���k�B��l operator / ()
template <class T>
Vector<T> Vector<T>::operator/(const T& f)
{
	Vector<T> Temp(Size);
	for (int i=1; i<= Size; i++)
		Temp.V[i]= V[i]/f;
	return Temp;
}

#endif