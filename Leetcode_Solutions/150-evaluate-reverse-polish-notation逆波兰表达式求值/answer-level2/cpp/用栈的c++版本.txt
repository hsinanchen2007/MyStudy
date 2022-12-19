### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/6bd0d5b723465fe7d1812aaa3eed45b6fc575c9af18c174b89eb0e5c3dc43565-%E6%8D%95%E8%8E%B7.PNG)
用栈的c++版本。
如果是数字就压入栈，字符串到数字转换用stoi。
如果是符号就把栈头两个数字出栈，然后进行运算后再入栈。
直到栈里只剩下一个数字。

### 代码

```cpp
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
        int num1,num2;
		for (string s : tokens) {
			if (s == ("+")) {
				num1 = st.top(); st.pop();
			    num2 = st.top(); st.pop();
				st.push(num2+num1);
			}
			else if (s == ("-")) {
				num1 = st.top(); st.pop();
				num2 = st.top(); st.pop();
				st.push(num2 - num1);
			}
			else if (s == ("*")) {
				num1 = st.top(); st.pop();
				num2 = st.top(); st.pop();
				st.push(num2 * num1);
			}
			else if (s == ("/")) {
				num1 = st.top(); st.pop();
				num2 = st.top(); st.pop();
				st.push(num2 / num1);
			}
			else {
				st.push(stoi(s));
			}
		}
		return st.top();
	}
};
```