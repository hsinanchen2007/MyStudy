可以将一个字符串拆成三部分：num1 + 'e'/'E' + num2，第二、三部分要么都存在，要么都不存在。
按一下步骤判断是否合法：
1. 判断num1是否合法，不合法返回false
2. 判断num1后字符串是否结束，是则返回true
3. 判断下一个字符是否为'e'/'E'，不是则返回false
4. 判断num2是否合法，合法返回true，否则返回false

```
class Solution {
public:
    //isNum函数判断以firstNo位置开始的num1/num2是否合法，若合法则返回num1/num2的后一个位置，否则返回-1，findedDot=true时小数不合法
    int isNum(string s, int firstNo, bool findedDot = false)
{
	if (firstNo > s.size())
	{
		return -1;
	}
	bool findedNum = false;
	if (s[firstNo - 1] == '+' || s[firstNo - 1] == '-')//匹配正负号
	{
		firstNo++;
	}
	for (; firstNo <= s.size(); firstNo++)
	{
		if (!findedDot&&s[firstNo - 1] == '.')//第一次找到小数点
		{
			findedDot = true;   
		}
		else if (s[firstNo - 1] >= '0' && s[firstNo - 1] <= '9')//找到一个数
		{
			findedNum = true;
		}
		else
		{
			break;   //其它情况下跳出循环，当前的firstNo将作为num1/num2的后一个位置返回
		}
	}
	if (!findedNum)
	{
		return -1;
	}
	return firstNo;
}
bool isNumber(string s)
{
	int nextNo = 1;
	while (nextNo <= s.size() && s[nextNo - 1] == ' ')//除去前面的空格
	{
		nextNo++;
	}
	nextNo = isNum(s, nextNo);//判断num1是否合法
	if (nextNo >= 1 && nextNo <= s.size() && (s[nextNo - 1] == 'e' || s[nextNo - 1] == 'E'))//判断num2是否合法
	{
		nextNo = isNum(s, nextNo + 1, true);
	}
	while (nextNo >= 1 && nextNo <= s.size() && s[nextNo - 1] == ' ')//除去后面的空格
	{
		nextNo++;
	}
	return nextNo > int(s.size());//nextNo要么为-1，要么为s.size()+1
}
};
```
