// UnaryF.h
// --------------------------------------
#ifndef UNARYF_H
#define UNARYF_H
#include <iostream>
using namespace std;
class Float
{
// �ŧi Prefix operator! ()
	friend Float operator! (const Float& F1);
// �ŧi Prefix operator--()
	friend Float& operator--(Float& F1);
// �ŧi Postfix operator--()
	friend Float operator--(Float& F1, int);
	private:
		float F;
	public:
		Float(float x) : F(x) {}
		Float(): F(0) {}
// �ϥΦ�����Ʃw�q �ഫ�B��l float
  operator float() {return F;}
// �ϥΦ�����Ʃw�q Prefix -
	Float operator-() const
	{return Float(-F);}
// �ϥΦ�����Ʃw�q Prefix operator ++ ()
	Float& operator++()
  {
		++F;
		return *this;
  }
// �ϥΦ�����Ʃw�q Postfix operator ++ ()
	Float operator++(int)
	{
		Float Before(F);
		F++;
		return Before;
	}
};
// �ϥ� friend ��Ʃw�q Prefix operator !()
Float operator!(const Float& F1)
	{return Float(F1.F*F1.F);}
// �ϥ� friend ��Ʃw�q Prefix operator --
Float& operator --(Float& F1)
	{F1.F--; return F1;}
// �ϥ� friend ��Ʃw�q Postfix operator -- ()
Float operator --(Float& F1, int)
{
	Float Before(F1.F);
	F1.F--;
	return Before;
}

#endif