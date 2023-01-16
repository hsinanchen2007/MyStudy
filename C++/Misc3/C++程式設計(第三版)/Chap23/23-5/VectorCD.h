// VectorCD.h

#ifndef VectorCD_H
#define VectorCD_H

#include <iostream>
#include <iomanip>
using namespace std;

// ------宣告 Vector 樣版類別----------------------
template <class T>
class Vector
{
private:
	int Size;
	T* V;
	static int CountConst, CountDist;
	inline void Create(int);
public:
	// 宣告建構函數
	Vector(): Size(1){Create(1);}
	Vector(int N): Size(N){Create(N);}
	Vector(int, const T*);
	// 宣告解構函數
	~Vector();
};
// ----- 將 static 資料成員初始化 -----------------
template <class T>
int Vector<T>::CountConst = 0;
template <class T>
int Vector<T>::CountDist = 0;

// ----- 定義 Vector 樣版類別 ---------------------
// 成員函數 Create() 的定義
template <class T>
void Vector<T>::Create(int N)
{  
	if(N < 0)
	{
		Size = 0; V = 0;
		cerr << " 呼叫建構函數發生錯誤,"
				<< " 向量長度不能為負值!\n";
	}
	else
	{
		Size = N; V = new T[N+1];
		CountConst++;
		cout << " 第 "<< CountConst
				<< " 次呼叫建構函數\n";
	}
}
// 解構函數的定義
template <class T>
Vector<T>::~Vector()
{ 
	delete [] V;
	CountDist++;
	cout << " 第 "<< CountDist
			<< " 次呼叫解構函數" << endl;
}
#endif