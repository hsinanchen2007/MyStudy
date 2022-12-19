### 解题思路
![2.png](https://pic.leetcode-cn.com/9ab92e1649d6a29f665a5204db64fa9b7bb1ef20d2c2d94234646bf17ee06abc-2.png)

### 代码
```cpp
class Solution {
public:
	int distinctEchoSubstrings(string text) {
		string_view t(text);
        int n = t.size();

		unordered_set<string_view>res;
		for (int i = 0; i < n; ++i)
		{
			for (int len = 1; i + 2 * len <= n; ++len)
			{
				if (t.substr(i, len) == t.substr(i + len, len))
					res.insert(t.substr(i, len));
			}
		}
		return (int)res.size();
	}
};

```