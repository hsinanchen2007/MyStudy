### 解题思路
使用了数组做哈希，降低了出栈入栈的比较复杂性。

### 代码

```cpp
class Solution {
public:
	bool isValid(string s) {
		vector<int> s_map(s.length(), 0);
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') s_map[i] = 1;
			if (s[i] == ')') s_map[i] = -1;
			if (s[i] == '{') s_map[i] = 2;
			if (s[i] == '}') s_map[i] = -2;
			if (s[i] == '[') s_map[i] = 3;
			if (s[i] == ']') s_map[i] = -3;
		}
		stack<char> Valid_sta;
		for (auto x : s_map) {
			if (!Valid_sta.empty()) {
				if (!(Valid_sta.top() + x)) Valid_sta.pop();
				else {
					Valid_sta.push(x);
				}
			}
			else Valid_sta.push(x);
		}

		return Valid_sta.empty();
	}
};
```