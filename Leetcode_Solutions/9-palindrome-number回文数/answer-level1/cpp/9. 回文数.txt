### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
   bool isPalindrome(int x) 
	{
		if (0 > x)
		{
			return false;
		}
		int nH = 0;
		int nTemp = x;
        int nMax = 0x7fffffff / 10;
		while (nTemp > 0)
		{
            if (nH >= nMax)
			{
				return false;
			}
            nH = nH * 10;
			nH += nTemp % 10;
			nTemp /= 10;
		}
		return nH == x;
	}
};
```