### 解题思路
习惯性看到字符串对应出现次数的题想到hashmap。总觉得还能改进，使得答案更加简单。意犹未尽，欢迎赐教。

### 代码

```cpp
class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> m;
		if (s.size() != t.size()) return false;
		for (auto c : s) ++m[c];
		for (auto a : t) {
			--m[a];
		}
		for (unordered_map<char, int>::iterator it = m.begin(); it != m.end(); ++it) {
			if (it->second == 0)continue;
			else
			{
				return false;
			}
		}
		return true;
	}
};
```