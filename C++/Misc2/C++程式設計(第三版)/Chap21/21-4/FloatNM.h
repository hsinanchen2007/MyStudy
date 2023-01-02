// FloatNM.h
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2003.11-) 
// All Rights Reserved.
// ���{�����v�ݩ� �iģ��
// �ϥήɥ����n��.
// --------------------------------------
#ifndef FLOATNM_H
#define FLOATNM_H
#include <iostream>
#include <cmath>
//#include <cmath>
using namespace std;

class Float
{
	friend Float
		operator+(const Float& Left,
			const Float& Right);
	friend Float
		operator*(const Float& Left,
			const Float& Right);
	friend Float
		operator^(const Float& Left,
			const Float& Right);
	friend Float&
		operator+=(Float& Left,
			const Float& Right);
	private:
		float F;
	public:
		Float(float x) : F(x) {}
		Float(): F(0) {}
// �w�q �ഫ�B��l float
	operator float() {return F;}
};

// �w�q operator+()
Float operator + (const Float& Left, const Float& Right)
	{return Float(Left.F + Right.F);}

// �w�q operator*()
Float operator * (const Float& Left, const Float& Right)
	{return Float(Left.F * Right.F);}

// �w�q operator^()
Float operator ^ (const Float& Left, const Float& Right)
	{return Float(pow(Left.F, Right.F));}

// �w�q operator+=()
Float& operator += (Float& Left, const Float& Right)
{  Left.F += Right.F;  return Left;}

#endif