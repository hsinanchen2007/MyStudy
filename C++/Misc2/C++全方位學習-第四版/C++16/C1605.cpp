//檔案名稱：d:\C++16\C1605.cpp
#include <iostream>
#include <cstring>
using namespace std;

class Distance	//自定Distance資料類別
{
	int feet;
	float inches;
public:
	class InError	//英吋值錯誤處理類別
	{
		char str[80];
		float i;
	public:
		InError(char *s, float f)
		{
			strcpy(str, s);
			i = f;
		}
		char* get_str()
		{
			return str;
		}
		float get_i()
		{
			return i;
		}
	};
	Distance()	//無參數建立者函數
	{
		feet = 0; inches = 0.0;
	}
	Distance(int ft, float in)	//有參數建立者函數
	{
		char s1[] = "建立錯誤英吋值 ";
		if(in >= 12)	//若in大於等於12
			throw InError(s1, in);	//則投擲例外
		feet = ft;	//否則feet = ft
		inches = in;	//	inches = in
	}
	void getDist()	//輸入資料函數
	{
		char s2[] = "輸入錯誤英吋值 ";
		cout << "請輸入英呎值：";
		cin >> feet;
		cout << "請輸入英吋值：";
		cin >> inches;
		if(inches >= 12)	//若inches大於等於12
			throw InError(s2, inches);	//則投擲例外
	}
};

int main(int argc, char** argv)
{
	try {			//try區塊
		Distance d1(10, (float)11.0);	//若英吋>=12.0則錯誤
		Distance d2;
		d2.getDist();	//輸入資料;
		cout << "輸入值正確。";
	}
	catch(Distance::InError ix) { //捕捉例外與接收錯誤類別
		cout << ix.get_str() << '\t'	//呼叫InError::get_str
			 << ix.get_i() << endl;	//呼叫InError::get_i
	}
	return 0;
}
