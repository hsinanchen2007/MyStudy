```C++ []
class Solution {
public:
	bool isFlipedString(string s1, string s2) {
		if (s1.length() != s2.length())
			return false;
		if ((s1 + s1).find(s2) != string::npos)
			return true;
		return false;
	}
};
```
