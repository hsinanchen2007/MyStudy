```C++ []
class Solution {
public:
	string reverseLeftWords(string s, int n) {
		string res = s + s;
		return res.substr(n, s.length());
	}
};
```
