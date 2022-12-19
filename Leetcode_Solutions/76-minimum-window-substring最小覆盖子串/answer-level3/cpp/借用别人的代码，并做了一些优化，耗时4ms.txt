首先，建一个int数组比维护一个字典b要方便而且快得多，元素比较也是与0比较，没有多余的取字典元素的操作(logn),
另外，需要更新minLength的时机必须满足两个条件：last_l != l&&r - last_l + 1 < minLength，
前者代表left后移了，即进入了while (len == tl)循环，后者代表确实找到了更小的长度，
而且，我们不需要每次更新都取一次子串，只需要记录子串的开始位置和长度，到最后再取。
![1569080324(1).png](https://pic.leetcode-cn.com/488b6379f3822e30280e101ab0a1903680d6d893e48d8125a669582035ff1d31-1569080324\(1\).png)

详见代码：
```
class Solution {
public:
	string minWindow(string s, string t) {
		if (s.empty() || t.empty())
			return "";
		int count[256] = { 0 };
		for (auto c : t) ++count[c];
		int begin = 0, len = 0, sl = s.length(), minLength = sl + 1, tl = t.length();
		string res;
		for (int l = 0, r = 0; r < sl; ++r) {
			if (--count[s[r]] >= 0)
			{
				++len;
				int last_l = l;
				while (len == tl) {
					last_l = l;
					if (++count[s[l++]] > 0) --len;
				}
				if (last_l != l&&r - last_l + 1 < minLength) {
					minLength = r - last_l + 1;
					begin = last_l;
				}
			}
		}
		if (minLength > sl)
			return "";
		else
			return s.substr(begin, minLength);
	}
};
```
