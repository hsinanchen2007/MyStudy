// UnaryF.h
// --------------------------------------
#ifndef UNARYF_H
#define UNARYF_H
#include <iostream>
using namespace std;
class Float
{
//  Prefix operator! ()
	friend Float operator! (const Float& F1);
//  Prefix operator--()
	friend Float& operator--(Float& F1);
//  Postfix operator--()
	friend Float operator--(Float& F1, int);
	private:
		float F;
	public:
		Float(float x) : F(x) {}
		Float(): F(0) {}
// ㄏノΘㄧ计﹚竡 锣传笲衡 float
  operator float() {return F;}
// ㄏノΘㄧ计﹚竡 Prefix -
	Float operator-() const
	{return Float(-F);}
// ㄏノΘㄧ计﹚竡 Prefix operator ++ ()
	Float& operator++()
  {
		++F;
		return *this;
  }
// ㄏノΘㄧ计﹚竡 Postfix operator ++ ()
	Float operator++(int)
	{
		Float Before(F);
		F++;
		return Before;
	}
};
// ㄏノ friend ㄧ计﹚竡 Prefix operator !()
Float operator!(const Float& F1)
	{return Float(F1.F*F1.F);}
// ㄏノ friend ㄧ计﹚竡 Prefix operator --
Float& operator --(Float& F1)
	{F1.F--; return F1;}
// ㄏノ friend ㄧ计﹚竡 Postfix operator -- ()
Float operator --(Float& F1, int)
{
	Float Before(F1.F);
	F1.F--;
	return Before;
}

#endif