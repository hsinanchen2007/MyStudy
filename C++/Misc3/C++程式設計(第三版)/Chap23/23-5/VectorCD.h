// VectorCD.h

#ifndef VectorCD_H
#define VectorCD_H

#include <iostream>
#include <iomanip>
using namespace std;

// ------�ŧi Vector �˪����O----------------------
template <class T>
class Vector
{
private:
	int Size;
	T* V;
	static int CountConst, CountDist;
	inline void Create(int);
public:
	// �ŧi�غc���
	Vector(): Size(1){Create(1);}
	Vector(int N): Size(N){Create(N);}
	Vector(int, const T*);
	// �ŧi�Ѻc���
	~Vector();
};
// ----- �N static ��Ʀ�����l�� -----------------
template <class T>
int Vector<T>::CountConst = 0;
template <class T>
int Vector<T>::CountDist = 0;

// ----- �w�q Vector �˪����O ---------------------
// ������� Create() ���w�q
template <class T>
void Vector<T>::Create(int N)
{  
	if(N < 0)
	{
		Size = 0; V = 0;
		cerr << " �I�s�غc��Ƶo�Ϳ��~,"
				<< " �V�q���פ��ର�t��!\n";
	}
	else
	{
		Size = N; V = new T[N+1];
		CountConst++;
		cout << " �� "<< CountConst
				<< " ���I�s�غc���\n";
	}
}
// �Ѻc��ƪ��w�q
template <class T>
Vector<T>::~Vector()
{ 
	delete [] V;
	CountDist++;
	cout << " �� "<< CountDist
			<< " ���I�s�Ѻc���" << endl;
}
#endif