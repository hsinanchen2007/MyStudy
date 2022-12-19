### 解题思路
看了剑指offer上的解题方法然后自己开始写的

一开始写的时候并没有把有符号（整数部分和指数部分）和无符号（小数部分）的处理分成两个函数写，然后开始疯狂报错
各种情况总是考虑得不全！然后开始老老实实分成两个函数写~~~  很重要得就是得去空格，这样会省事很多

然后就是   scanUnsignedInteger(s) || isNum , scanUnsignedInteger(s) 和 isNum 关于 || 先后顺序问题
我之前把 isNum 放在前面了， 0.9 得时候结果错误~~  因为0.9 整数部分isNum已经为真了
isNum ||  scanUnsignedInteger(s) ， 后面得 scanUnsignedInteger(s) 就不会在判断了此时flag < size
所以结果错误~~~   或者isNum | scanUnsignedInteger(s) 这样写也是ok得



### 代码

```cpp
class Solution {
public:
int flag = 0;
bool isNumber(string& s) {
	bool isNum = false;
	if (s == " ")
	{
		return false;
	}
	int start = s.find_first_not_of(' ');
	int end = s.find_last_not_of(' ');
	s = s.substr(start, end-start+1);

	isNum = scanInterger(s);

	if (s[flag] == '.')
	{
		flag++;
		isNum = scanUnsignedInteger(s) || isNum ;
	}

	if (s[flag] == 'e' || s[flag] == 'E')
	{
        flag++;
		isNum = isNum && scanInterger(s);
	}

	return isNum && flag >= s.size();
}

bool scanUnsignedInteger(string& s) {

	int tmp = flag;
	while (flag < s.size() && s[flag] >='0' && s[flag]<='9')
	{
		flag++;
	}
	return flag > tmp;
}

bool scanInterger(string& s) {

	if (s[flag] == '+' || s[flag] == '-')
	{
		flag++;
	}

	return scanUnsignedInteger(s);
}
};
```