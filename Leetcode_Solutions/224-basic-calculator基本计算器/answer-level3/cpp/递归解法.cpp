**使用递归，易于实现且复杂度低**

![image.png](https://pic.leetcode-cn.com/0426d0afd286e8f89fe670bb3ff0425b2f22bee9a86f821958646c1039b2f262-image.png)

```
class Solution {
public:
	int calculate(const string& str) {
		int idx = 0;
		return calculate(str, idx);
	}

	int calculate(const string& str, int& idx) {
		int64_t res = 0;
		for (char opr = '+'; idx < str.size();) {
			switch (str[idx]) {
			case '+':
			case '-':
				opr = str[idx++];
				break;
			case '(':
				++idx;
				res += opr == '+' ? calculate(str, idx) : -calculate(str, idx);
				break;
			case ')':
				++idx;
				return res;
			default:
				if (isdigit(str[idx])) {
					int64_t x = str[idx++] - '0';
					while (idx < str.size() && isdigit(str[idx]))
						x = x * 10 + str[idx++] - '0';
					res += opr == '+' ? x : -x;
				} else {
					++idx;
				}
				break;
			}
		}
		return res;
	}
};
```cpp
