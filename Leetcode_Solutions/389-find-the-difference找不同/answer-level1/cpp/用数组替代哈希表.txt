执行用时 :4 ms, 在所有 C++ 提交中击败了89.18%的用户
内存消耗 :6.5 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
	char findTheDifference(string s, string t) 
	{
		int hash[26] = { 0 };
		for (int i = 0; i < s.size(); ++i)
			hash[s[i] - 'a']++;
		for (int i = 0; i < t.size(); ++i)
		{
			hash[t[i] - 'a']--;
			if (hash[t[i] - 'a'] == -1)
				return t[i];
        	}
		return -1;
	}
};
```