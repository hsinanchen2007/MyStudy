### 解题思路
两个字符串排序并比较每个字符是否相同。
若字符串长度相同，且每个字符相同，则满足题意

### 代码

```cpp
class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		int n = s1.size(), m = s2.size();
		if (n != m) return false;
		
		sort(s1.begin(), s1.end());
		sort(s2.begin(),s2.end());
		for (int i = 0, j = 0; i < n, j < m; i++, j++)
		{
			if (s1[i] != s2[j])return false;
		}
		return true;
	}
};
```