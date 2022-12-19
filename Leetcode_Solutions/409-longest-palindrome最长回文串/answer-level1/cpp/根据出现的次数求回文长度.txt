### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
		//出现2n次 长度加n
		//出现2n+1次，长度加n
		//如果有出现奇数次的就最后加1好了。不管有几个奇数次的字母，都只能用一个啊
		map<char, int> charCount;
		for (char c : s)
		{
			charCount[c]++;
		}
		int result = 0;
		bool hasOdd = false;
		map<char, int>::iterator it;
		for (it=charCount.begin();it!=charCount.end();it++)
		{
			if (it->second % 2 == 0)
				result = result +it->second ;
			else
				{
                result = result +(it->second-1) ;
                hasOdd = true;
                }
		}

		if (hasOdd)
			result++;
		return result;
    }
};
```