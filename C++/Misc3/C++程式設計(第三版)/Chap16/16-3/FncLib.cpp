// FncLib.cpp
// --------------------------------------
#include "First.h"
#include "Second.h"

// �w�q��� NS1::Fnc()
double NS1::Fnc(double x)
{
	return x*NS1::Gain;
}

// �w�q��� NS2::Fnc()
double NS2::Fnc(double x)
{
	return x*NS2::Gain;
}
