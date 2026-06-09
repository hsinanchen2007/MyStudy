### 解题思路
遍历字符串，以当前字符为回文中心，向两侧扩展，得到当前的最长回文字符串长度
进行对比，得到最长长度及保存起始终止位置

### 代码

```cpp
class Solution {
private:
	int curLongestPalindrome(string str, int left, int right) {
		int curLen = 0;
		while (left >= 0 && right < str.length() && str.at(left) == str.at(right)) {
			curLen = right - left + 1;
			left--;
			right++;
		}
		return curLen;
	}
public:
	string longestPalindrome(string s) {
		if (s.length() == 0) { return string(); }
		int startPos = 0, endPos = 0, maxLen = 0, curLen = 0;
		for (int i = 0; i < s.length(); i++) {
			int len1 = curLongestPalindrome(s, i, i);
			int len2 = curLongestPalindrome(s, i, i + 1);
			curLen = (len1 < len2) ? len2 : len1;
			if (maxLen < curLen) {
				maxLen = curLen;
				startPos = i - (curLen - 1) / 2;
				endPos = i + curLen / 2;
			}
		}
		return string(s, startPos, maxLen);
	}
};
```