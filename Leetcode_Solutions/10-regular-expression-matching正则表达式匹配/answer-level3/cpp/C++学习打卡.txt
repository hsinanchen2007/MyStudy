### 解题思路
递归思路，动态规划还没看懂

### 代码

```cpp
class Solution {
public:
	bool isMatch(string s, string p) {
		if (s.length() == 0 && p.length() == 0) { return true; }
		else if (s.length() != 0 && p.length() == 0) { return false; }
		else if (s.length() == 0 && p.length() != 0) {
			if (p.length() % 2 == 1) { return false; }
			for (int i = 0; i < p.length(); i += 2) {
				if (p[i + 1] != '*') { return false; }
			}
			return true;
		}
		else {
			if (p.length() == 1 || p[1] != '*') {
				if (s[0] == p[0] || p[0] == '.') {
					return isMatch(string(s, 1), string(p, 1));
				}
				else {
					return false;
				}
			}
			else {
				if (s[0] != p[0] && p[0] != '.') {
					if (isMatch(s, string(p, 2)) == true) { return true; }
				}
				else {
					if (isMatch(s, string(p, 2)) == true) { return true; }
					if (isMatch(string(s, 1), p) == true) { return true; }
				}
				return false;
			}
		}
	}
};
```