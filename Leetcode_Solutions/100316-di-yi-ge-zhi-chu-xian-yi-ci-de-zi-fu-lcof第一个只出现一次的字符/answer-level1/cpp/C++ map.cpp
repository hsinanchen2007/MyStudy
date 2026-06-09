### 解题思路
先统计出每个字符的出现次数
再按照s中字符的顺序进行遍历

### 代码

```cpp
class Solution {
public:
	char firstUniqChar(string s) {
		char res=' ';
		map<char, int> hashMap;
		for (auto it=s.begin();it!=s.end();it++)
		{
			++hashMap[*it];
		}
		for (auto it = s.begin(); it != s.end(); it++)
		{
			if (hashMap[*it] == 1) return *it;
		}
		return res;
	}
};
```