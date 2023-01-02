// Float.h
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2003.12-) 
// All Rights Reserved.
// 本程式版權屬於 張耀仁
// 使用時必需聲明.
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

	// 定義 operator+()
	Float operator + (const Float& F2) const
	{
		return Float(F + F2.F); 
	}
	// 定義 operator*()
	Float operator * (const Float& F2) const
	{
		return Float(F * F2.F); 
	}
	// 定義 operator^()
	Float operator ^ (const float& f)  const
	{
		return Float(pow(F,f));
	}
	// 定義 轉換運算子 float
	operator float() 
	{ 
		return F; 
	}
	// 定義 operator += ()
	Float& operator += (const Float& F2)
	{
		F += F2.F;
		return *this;
	}
};
#endif 