一开始没给c赋初始值，在`s="",t="y"`这个例子上出错了。
```C++ []
class Solution {
public:
	char findTheDifference(string s, string t) {
		char c = 0;
		for (int i = 0; i < s.length(); i++) {
			c ^= s[i];
		}
		for (int i = 0; i < t.length(); i++) {
			c ^= t[i];
		}
		return c;
	}
};
```
