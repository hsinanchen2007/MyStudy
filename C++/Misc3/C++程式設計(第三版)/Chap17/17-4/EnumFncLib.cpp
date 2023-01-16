// EnumFncLib.cpp
// --------------------------------------
#include <cmath>
using std::fabs;

// 定義 enum資料型態ErrorStates
enum ErrorStates {OK, OverFlow, UnderFlow};
const float Epsilon = 1.0E-16;
extern const int Size = 5;

// 函數 ShowVectorElement() 的定義 
float ShowVectorElement(float A[],int N)
{
	ErrorStates State = OK;
	if (N>=Size)
	{ 
		State = OverFlow;
		throw State;
	}
	if (N < 0)
	{ 
		State = UnderFlow;
		throw State;
	}
	return A[N];
}
