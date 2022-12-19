### 解题思路
这里因为查重但不能重新排列，所以不能用hashmap统计字符出现次数的方法。所以采用双重遍历的方法。

### 代码

```cpp
class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {

		sort(d.begin(), d.end(), [](string a, string b) {
			if (a.size() == b.size()) return a < b;
			return a.size() > b.size();
		});

		for (auto str : d) {
			int i = 0;
			for (auto c : s) {
				if (i < str.size() && c == str[i]) ++i;
			}
			if (i == str.size()) return str;
		}
		return "";
		
	}
};
```