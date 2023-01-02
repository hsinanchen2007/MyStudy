// Float.h
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2003.12-) 
// All Rights Reserved.
// ���{�����v�ݩ� �iģ��
// �ϥήɥ����n��.
// --------------------------------------
#ifndef FLOAT_H
#define FLOAT_H
#include <iostream>
#include <cmath>
using namespace std;
class Float
{
	private:
		float F;
	public:
		Float(float x) : F(x) {}
		Float(): F(0) {}

	// �w�q operator+()
	Float operator + (const Float& F2) const
	{
		return Float(F + F2.F); 
	}
	// �w�q operator*()
	Float operator * (const Float& F2) const
	{
		return Float(F * F2.F); 
	}
	// �w�q operator^()
	Float operator ^ (const float& f)  const
	{
		return Float(pow(F,f));
	}
	// �w�q �ഫ�B��l float
	operator float() 
	{ 
		return F; 
	}
	// �w�q operator += ()
	Float& operator += (const Float& F2)
	{
		F += F2.F;
		return *this;
	}
};
#endif 