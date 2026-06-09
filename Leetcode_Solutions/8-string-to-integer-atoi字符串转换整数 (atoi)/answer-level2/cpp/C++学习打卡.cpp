### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int myAtoi(string str) {
		if (str.length() == 0) { return 0; }
		int i = 0, signal = 0;
		while (i < str.length() && str.at(i) == ' ') { i++; }
		if (i == str.length()) { return 0; }
		else {
			if (str.at(i) == '-') { signal = -1; i++; }
			else if (str.at(i) == '+') { signal = 1; i++; }
			else if (str.at(i) >= '0' && str.at(i) <= '9') { signal = 1; }
			else { return 0; }
		}

		int ans = 0;
		while (i < str.length() && str.at(i) >= '0' && str.at(i) <= '9') {
			if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && str.at(i) - '0' > 7)) { return INT_MAX; }
			if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && str.at(i) - '0' > 8)) { return INT_MIN; }
			ans = ans * 10 + signal * (str.at(i) - '0');
			i++;
		}
		return ans;
	}
};
```