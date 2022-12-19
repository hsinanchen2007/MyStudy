纯暴力，不用脑子，写起来快一点。

```C++ []
class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		int res = 0;
		unordered_multiset<char> s;
		for (char c : chars) {
			s.insert(c);
		}
		for (string word : words) {
			unordered_multiset<char> tmp(s);
			bool flag = true;
			for (char c : word) {
				auto it = tmp.find(c);
				if(it !=tmp.end())
					tmp.erase(it);
				else {
					flag = false;
					break;
				}
			}
			if (flag)
				res += word.length();
		}
		return res;
	}
};
```
