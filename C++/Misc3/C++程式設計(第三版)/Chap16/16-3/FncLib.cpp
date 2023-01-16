// FncLib.cpp
// --------------------------------------
#include "First.h"
#include "Second.h"

// 定義函數 NS1::Fnc()
double NS1::Fnc(double x)
{
	return x*NS1::Gain;
}

// 定義函數 NS2::Fnc()
double NS2::Fnc(double x)
{
	return x*NS2::Gain;
}
