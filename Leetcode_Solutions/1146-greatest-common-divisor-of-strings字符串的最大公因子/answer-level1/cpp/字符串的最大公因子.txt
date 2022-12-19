### 解题思路
求两字符串长度的最大公约数

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2)
    {
		string str = str1;
		int nSize1 = str1.size();
		int nSize2 = str2.size();
		if (nSize1 < 1 || nSize2 < 1)
		{
			return string();
		}
		int nNum = GetDivisor(nSize2, nSize1);
		string strTemp = str.substr(0, nNum);
		string strT1;
		for (int i = 0; i < nSize1 / nNum; i++)
		{
			strT1 += strTemp;
		}
		string strT2;
		for (int i = 0; i < nSize2 / nNum; i++)
		{
			strT2 += strTemp;
		}
		if (strT2 == str2 &&  strT1 == str1)
		{
			return strTemp;
		}
		return string();

	} 
private:
	//计算最大公约数
	int GetDivisor(int m, int n)
	{
		if (n > m)
		{
			m ^= n;
			n ^= m;
			m ^= n;
		}
		int nTemp = 0;
		while (n > 0)
		{
			nTemp = m % n;
			if (nTemp == 0)
			{
				return n;
			}
			m = n;
			n = nTemp;
		}
		return 1;
	}
};
```