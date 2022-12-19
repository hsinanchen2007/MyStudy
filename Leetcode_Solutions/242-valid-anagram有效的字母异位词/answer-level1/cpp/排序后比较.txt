执行用时 :32 ms, 在所有 C++ 提交中击败了27.37%的用户
内存消耗 :9.7 MB, 在所有 C++ 提交中击败了5.07%的用户

### 代码

```cpp
class Solution {
public:
	bool isAnagram(string s, string t) 
	{
		if (s.size() != t.size()) return false;
		sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != t[i])
				return false;
		}
		return true;
	}
};
```