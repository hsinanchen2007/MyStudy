### 解题思路
此处撰写解题思路
啊...
### 代码
这...
```cpp
class Solution {
public:
    bool judg(string s, int l, int r)
{
	while (l<r)
	{
		if(s[l] != s[r]) return false;
		l++;
		r--;
	}
	return true;
}
    bool validPalindrome(string s) {
	int l = 0, r = s.length()-1;
	while (l < r)
	{
		if(s[l] == s[r])
		{
			l++;
			r--;
		}
		else if (s[l] != s[r])
		{
            if(s[l+1] != s[r] && s[l] != s[r-1])
            {
                return false;
            }
			bool t = judg(s,l+1,r-2)||judg(s,l+2,r-1);
			return t;
		}
	}
    return true;
}
};
```