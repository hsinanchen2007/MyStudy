### 解题思路
遍历字符串，在哈希表中没找到则添加进去，自增当前长度；找到了刷新最大长度和当前长度。

### 代码

```cpp
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> mapStr;
		int len = 0, maxLen = 0, temp = 0;
		for (int i = 0; i < s.length(); i++) {
			auto iter = mapStr.find(s[i]);
			if (iter != mapStr.end()) {
				maxLen = max(maxLen, len);
				temp = max(temp, iter->second);
				len = i - temp;
				iter->second = i;
			}
			else {
				mapStr.emplace(s[i], i);
				len++;
			}
		}
		maxLen = max(maxLen, len);
		return maxLen;
	}
};
```