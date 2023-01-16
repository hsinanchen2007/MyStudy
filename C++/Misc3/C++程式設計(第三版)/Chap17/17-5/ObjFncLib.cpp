// ObjFncLib.cpp
// --------------------------------------
#include "Common.h"
using namespace ExcNameSpace;

// ��� ShowVectorElement() ���w�q
float ShowVectorElement(float A[],int N)
{
	if (N>=Size)
		{ throw OverFlow();  }
	if (N < 0)
		{ throw UnderFlow(); }
	return A[N];
}
