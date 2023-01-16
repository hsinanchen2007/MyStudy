// EnumFncLib.cpp
// --------------------------------------
#include <cmath>
using std::fabs;

// �w�q enum��ƫ��AErrorStates
enum ErrorStates {OK, OverFlow, UnderFlow};
const float Epsilon = 1.0E-16;
extern const int Size = 5;

// ��� ShowVectorElement() ���w�q 
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
