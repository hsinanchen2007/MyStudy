### 解题思路
回文组成的字符有两种：
1.字母数是偶数的，刚好构成回文的两端。
2.字母数是奇数的，就要分类讨论了
   （1）字母数字是奇数但是大于1，去掉一个就是偶数，刚好能做回文的两端。
   （2）字母数刚好等于1，刚好这个字母就放回文最中间那个位置
   是字母数奇数的情况，就要考虑最后再加一。
### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
       int maxLength = 0;
	map<char, int>mapChars;
	for (int i = 0; i < s.size(); i++)
		mapChars[s[i]]++;
	bool temp = false;
	for (map<char, int>::iterator it = mapChars.begin(); it != mapChars.end(); it++)
	{
		if ((it->second) % 2 == 0)
			maxLength += it->second;
		else 
		{
			if (it->second > 1) 
			{
				temp = true;
				maxLength += it->second - 1;
			}
			else if(it->second == 1)
				temp = true;
		}
	}
	if (temp)
		maxLength++;
	return maxLength ;
    }
};
```