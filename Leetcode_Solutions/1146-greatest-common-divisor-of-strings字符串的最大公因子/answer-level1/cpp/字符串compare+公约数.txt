### 解题思路
1.从str1 ,str2 中短的为基准搜索；
2.用公约数排除错误解；
3.基本判断

### 代码

```cpp
class Solution {
public:
	string gcdOfStrings(string str1, string str2) 
	{
//确定短str
		int length = 0;
		string L, S;
		if (str1.size() > str2.size())
		{
			L = str1;
			S = str2;
			length = str2.size();
		}
		else
		{
			L = str2; 
			S = str1;
			length = str1.size();
		}

		for (int i = 1; i <= length; i++)
		{
//公约数排除
			if (S.size() % i != 0)
				continue;
			int tmpLength = length/i;
			
			string tmpS;
			tmpS = S.substr(0,tmpLength );
			if (strCompare(S, tmpS) && strCompare(L, tmpS))
			{
				return tmpS;
			}
		}
		return "";

	}
//基本判断
	bool strCompare(string Dst, string sub)
	{
		if (sub == "")
			return true;
		if (Dst.size() % sub.size() != 0)
			return false;
		string tmp;
		int t = Dst.size() / sub.size();
		for (int i = 0; i < t; i++)
		{
			tmp += sub;
		}
		if (Dst.compare(tmp) != 0)
			return false;
		else
		{
			return true;
		}

	}
};
```