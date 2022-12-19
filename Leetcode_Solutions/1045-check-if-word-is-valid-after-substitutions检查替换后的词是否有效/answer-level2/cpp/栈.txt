### 解题思路
考查栈，遇到C的时候就pop，然后pop B，然后pop A，如果不行，直接退出false。

### 代码

```cpp
class Solution {
public:
    bool isValid(string S) {
        if (S.empty()) {
			return false;
		}
		stack<char> strStack;
		for (int i = 0; i < S.size(); i++) {
			strStack.push(S[i]);
			while(! strStack.empty()) {
				if (strStack.top() == 'c') {
					strStack.pop();
					if (! strStack.empty() && strStack.top() == 'b') {
						strStack.pop();
						if (! strStack.empty() && strStack.top() == 'a') {
							strStack.pop();
						} else {
							return false;
						}
					} else {
						return false;
					}
				} else {
					break;
				}
			}
		}
		if (! strStack.empty()) {
			return false;
		} else {
			return true;
		}
	}
};
```