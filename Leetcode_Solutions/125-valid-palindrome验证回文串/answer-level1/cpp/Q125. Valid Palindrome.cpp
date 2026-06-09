#### 回文串
简单明了的题目，判断指定字符串是否是回文串。
题设说不区分大小写，因此首先将原串中的大写字母转成小写。由于还不习惯使用stl里的函数，所以自己另外写了判断和转换函数。
使用首尾指针，通过判断首尾指针指向的字符是否相等，如果相等，首尾指针向中间靠拢；如果不相等，则不是合法的回文串。
```
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() <= 1)
			return true;

		// 先全部转成小写字母
		this->toLowerCase(s);

		string::size_type l = 0, r = s.size() - 1;
		while (l < r) {
			// 忽略非法字符
			while (l < r && !isValidChar(s[l])) ++l;
			while (l < r && !isValidChar(s[r])) --r;
			if (l >= r)
				return true;

			// 不相等则不是回文串
			if (s[l] != s[r])
				return false;

			// 向中间靠拢
			++l;
			--r;
		}

		return true;
	}

	bool isValidChar(char c) {
		return '0' <= c && c <= '9'
			|| 'a' <= c && c <= 'z';
	}

	bool isUpperCase(char c) {
		return 'A' <= c && c <= 'Z';
	}

	void toLowerCase(string& s) {
		for (string::size_type i = 0; i < s.size(); ++i) {
			if (isUpperCase(s[i]))
				s[i] += 0x20;
		}
	}
};

```
我果真不适合写题解，写文章啊！