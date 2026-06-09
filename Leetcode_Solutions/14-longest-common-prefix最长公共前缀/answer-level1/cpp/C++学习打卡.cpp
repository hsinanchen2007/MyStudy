### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) { return {}; }
		
		int maxLen = INT_MAX;
		for (string cur : strs) {
			maxLen = (maxLen > cur.length()) ? cur.length() : maxLen;
		}
		string ans;
		for (int i = 0; i < maxLen; i++) {
			char c = strs[0][i];
			for (int j = 1; j < strs.size(); j++) {
				if (c != strs[j][i]) { return ans; }
			}
			ans.push_back(c);
		}
		return ans;
	}
};
```