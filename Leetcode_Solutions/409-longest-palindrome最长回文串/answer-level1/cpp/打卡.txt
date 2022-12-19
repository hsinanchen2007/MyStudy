### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
		map<char,int>str;
		for(int i=0;i<s.length();i++)
		{
			if(str.find(s[i])!=str.end())
				str[s[i]]++;
			else
				str[s[i]]=1;
		}
		int one=0,ans=0;
		for(map<char,int>::iterator p=str.begin();p!=str.end();p++)
		{
			ans+=p->second/2*2;
			one+=p->second%2;
		}
		if(one!=0)
			ans++;
			return ans;
    }
};
```