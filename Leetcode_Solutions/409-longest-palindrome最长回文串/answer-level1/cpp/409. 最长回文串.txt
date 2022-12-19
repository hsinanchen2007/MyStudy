### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) 
	{
		int nRes = 0;
		char vec[58] = { 0 };
		int nSize = s.size();
		for (int i = 0; i < nSize; i++)
		{
			if (1 == vec[s[i] - 'A'])
			{
				vec[s[i] - 'A'] = 0;
				nRes += 2;
			}
			else
			{
				vec[s[i] - 'A'] ++;
			}
		}
		for (int i = 0; i < 58; i++)
		{
			if (0 != vec[i])
			{
				nRes++;
                break;
			}

		}
		return nRes;
	}
};
```