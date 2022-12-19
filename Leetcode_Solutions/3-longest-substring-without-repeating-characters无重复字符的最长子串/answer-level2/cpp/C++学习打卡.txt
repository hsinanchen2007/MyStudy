### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) { return 0; }
		int curMaxLen = 1;
		map<char, int>charIndex;
		charIndex.insert(pair<char, int>(s.at(0), 0));
		for (int i = 0, j = 1; j < s.length(); j++) {
			//cout << "char:" << s.at(j) << "  curMaxLen:" << curMaxLen << endl;
			if (charIndex.find(s.at(j)) == charIndex.end() || charIndex.at(s.at(j)) < i) {
				curMaxLen = max(curMaxLen, (j - i + 1));
			}
			else {
				i = charIndex.at(s.at(j)) + 1;
			}
			charIndex[s.at(j)] = j;
		}
		return curMaxLen;
	}
};
```