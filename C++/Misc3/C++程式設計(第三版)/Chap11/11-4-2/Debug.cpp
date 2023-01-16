// Debug.cpp
// --------------------------------------

#define Debug
#if defined(Debug)
#define Breakpoint(x)                                 \
  {                                                                 \
  cerr << #x << " 的值是: " << x << endl;  \
  cerr << "按 Enter 鍵繼續." << endl;         \
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

// 定義 inline 函數 Rand()  產生 0 ~ 1  之間的亂數
inline double Rand()
{
	return double(rand())/RAND_MAX;
}

// ---- 主程式 -------------------------------------
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
