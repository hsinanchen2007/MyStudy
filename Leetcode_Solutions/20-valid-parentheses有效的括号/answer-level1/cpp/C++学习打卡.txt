### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	bool isValid(string s) {
		if (s.length() == 0) { return true; }

		bool ans = true;
		stack<char>myStack;
		myStack.push('#');
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				myStack.push(s[i]);
			}
			else if (s[i] == ')' && myStack.top() == '(') {
				myStack.pop();
			}
			else if (s[i] == ']' && myStack.top() == '[') {
				myStack.pop();
			}
			else if (s[i] == '}' && myStack.top() == '{') {
				myStack.pop();
			}
			else {
				stack<char>().swap(myStack);
				return false;
			}
		}
		ans = (myStack.top() == '#') ? true : false;
		stack<char>().swap(myStack);
		return ans;
	}
};
```