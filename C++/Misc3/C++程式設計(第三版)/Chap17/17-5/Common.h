//Common.h
// --------------------------------------
#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

namespace ExcNameSpace
{
	class OverFlow  { };
	class UnderFlow { };
	const int Size = 5;
	const float Epsilon = 1.0E-16;
}
// - ��� ShowVectorElement() ���쫬
	float ShowVectorElement(float [],int);

#endif