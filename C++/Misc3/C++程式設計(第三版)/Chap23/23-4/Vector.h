// Vector.h

#ifndef Vector_H
#define Vector_H

#include <iostream>
#include <iomanip>
//#include <conio>
using namespace std;

inline void Check(bool ErrorCondition,
  const string& Message = "Requirement failed")
{
    if (ErrorCondition)
    { cerr << &Message << endl; exit(1); }
}

// 宣告 Vector 樣版類別
// -----------------------------------------
template <class T>
class Vector
{
	// 宣告乘法運算子-1 operator * ()
	friend Vector<T> operator*(const T& , const Vector<T>& );    // Z3=f*Z2;
	// 宣告乘法運算子-2 operator * ()
	 friend Vector<T> operator*(const Vector<T>& , const T& );
	 private:
		int Size;
		T* V;
		inline void Create(int);
	public:
    // 宣告建構函數
    Vector(int);
    Vector(int, const T*);
    // 宣告複製建構函數
    Vector(Vector<T>&);
    // 宣告解構函數
    ~Vector();
    // Operators
    // 宣告指派運算子 operator = ()
    Vector<T> operator=(const Vector<T>&);
    // 宣告加法運算子 operator + ()
    Vector<T> operator+(const Vector<T>&);
    // 宣告減法運算子 operator - ()
    Vector<T> operator-(const Vector<T>&);
    // 宣告乘法運算子-3 operator * ()
    T operator*(const Vector<T>&);
    // 宣告除法運算子 operator / ()
    Vector<T> operator/(const T&);
    // 宣告索引運算子 operator [] ()
    T& operator[](int i)
      {
			Check(i>Size, "索引錯誤, 超過邊界!");
			return V[i];
      }
    // 宣告成員函數 Display()
    void Display();
};

// 定義 Vector 樣版類別
// -----------------------------------------
// 函數 Create() 的定義
template <class T>
void Vector<T>::Create(int N)
{
	if(N<1)
		{Size = 0; V = 0;}
   else
		{Size = N; V= new T[N+1];}
}

// 建構函數的定義
template <class T>
Vector<T>::Vector(int N)
{
	Create(N);
	return;
}

// 解構函數的定義
template <class T>
Vector<T>::~Vector()
  { delete [] V; }

// 複製建構函數的定義-1
template <class T>
Vector<T>::Vector(int N, const T* OldV)
{
	 Create(N);
	for (int i=1; i<= Size; i++)
		V[i]= OldV[i-1];
	return;
}

// 複製建構函數的定義-2
template <class T>
Vector<T>::Vector(Vector<T>& OldV)
{
	Create(OldV.Size);
	for (int i=1; i<= Size; i++)
		V[i]= OldV.V[i];
	return;
}

// 定義指派運算子 operator = ()
template <class T>
Vector<T> Vector<T>::operator=(const Vector<T>& V2)
{
	if (Size!=V2.Size)
		Create(V2.Size);
	for (int i=1; i<= Size; i++)
		V[i] = V2.V[i];
	return *this;
}

// 定義加法運算子 operator + ()
template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>& V2)
{
	Check(Size!=V2.Size,
		"加法運算錯誤, 長度不相同!");
	Vector<T> Temp(Size);
	for (int i=1; i<= Size; i++)
		Temp.V[i]= V[i]+V2.V[i];
	return Temp;
}

// 定義減法運算子 operator - ()
template <class T>
Vector<T> Vector<T>::operator-(const Vector<T>& V2)
{
	Check(Size!=V2.Size,
		"減法運算錯誤, 長度不相同!");
	Vector<T> Temp(Size);
	for (int i=1; i<= Size; i++)
		Temp.V[i]= V[i]-V2.V[i];
	return Temp;
}


// 定義乘法運算子-1  operator * ()
template <class T>
Vector<T> operator*(const T& f, const Vector<T>& V1)
{
     Vector<T> Temp(V1.Size);
	for(int i=1; i<=V1.Size; i++)
		Temp.V[i] = f * V1.V[i];
	return Temp;
}

// 定義乘法運算子-2  operator * ()
template <class T>
Vector<T> operator*(const Vector<T>& V1, const T& f)
{
     Vector<T> Temp(V1.Size);
     for(int i=1; i<=V1.Size; i++)
        Temp.V[i] = f * V1.V[i];
     return Temp;
}

// 定義乘法運算子-3 operator * ()
template <class T>
T Vector<T>::operator*(const Vector<T>& V2)
{
	 Check(Size!=V2.Size,
		"內積運算錯誤, 長度不相同!");
	T Product = 0;
	for (int i=1; i<= Size; i++)
		Product += V[i]*V2.V[i];
	return Product;
}

// 定義成員函數 Display()
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

// 定義除法運算子 operator / ()
template <class T>
Vector<T> Vector<T>::operator/(const T& f)
{
	Vector<T> Temp(Size);
	for (int i=1; i<= Size; i++)
		Temp.V[i]= V[i]/f;
	return Temp;
}

#endif