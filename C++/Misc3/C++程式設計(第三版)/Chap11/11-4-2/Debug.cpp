// Debug.cpp
// --------------------------------------

#define Debug
#if defined(Debug)
#define Breakpoint(x)                                 \
  {                                                                 \
  cerr << #x << " ���ȬO: " << x << endl;  \
  cerr << "�� Enter ���~��." << endl;         \
  cin.get();                                                      \
  }
#else
#define Breakpoint(x)
#endif
//----------------------------------

// #define NDEBUG
#undef NDEBUG
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
using namespace std;

// �w�q inline ��� Rand()  ���� 0 ~ 1  �������ü�
inline double Rand()
{
	return double(rand())/RAND_MAX;
}

// ---- �D�{�� -------------------------------------
int main()
{
	srand(int(time(0))); 
	const int Size = 20;
	double Data[Size];
	for (int i=0; i<Size; i++)
	{
		Data[i]= 10.0*Rand()-5.0;
		assert(i<Size);
	}
	Breakpoint(Data[Size-1]);
	system("PAUSE");
	return 0;
}
