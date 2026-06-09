### 解题思路
1. 双指针，i指向haystack，j指向needle。
2. 若当前字符相等，则j指向needle下一字符。
3. 若当前字符不等，则i指向haystack中上一次相等的第一个字符（下一次for循环i会自加），j指向needle首字符。
4. 若j已匹配完，返回haystack中匹配的字符串首字符位置。

### 代码

```cpp
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		if (haystack.size() < needle.size()) return -1;

		int i = 0;
		int j = 0;
		// 双指针，i指向haystack，j指向needle
		for (int i = 0; i < haystack.size(); ++i) {
			// 当前字符相等，则j指向needle下一字符
			if (haystack[i] == needle[j]) {
				j++;
			}
			// 当前字符不等，则i指向haystack中上一次相等的第一个字符（下一次for循环i会自加），j指向needle首字符
			else {
				i = i - j;
				j = 0;
			}
			// j已匹配完，返回haystack中匹配的字符串首字符位置
			if (j == needle.size()) {
				return i - needle.size() + 1;
			}
		}

		return -1;
	}
};
```