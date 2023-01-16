// ObjFncLib.cpp
// --------------------------------------
#include "Common.h"
using namespace ExcNameSpace;

// 函數 ShowVectorElement() 的定義
float ShowVectorElement(float A[],int N)
{
	if (N>=Size)
		{ throw OverFlow();  }
	if (N < 0)
		{ throw UnderFlow(); }
	return A[N];
}
