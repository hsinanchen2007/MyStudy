// FloatNM.h
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2003.11-) 
// All Rights Reserved.
// 本程式版權屬於 張耀仁
// 使用時必需聲明.
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
// 定義 轉換運算子 float
	operator float() {return F;}
};

// 定義 operator+()
Float operator + (const Float& Left, const Float& Right)
	{return Float(Left.F + Right.F);}

// 定義 operator*()
Float operator * (const Float& Left, const Float& Right)
	{return Float(Left.F * Right.F);}

// 定義 operator^()
Float operator ^ (const Float& Left, const Float& Right)
	{return Float(pow(Left.F, Right.F));}

// 定義 operator+=()
Float& operator += (Float& Left, const Float& Right)
{  Left.F += Right.F;  return Left;}

#endif