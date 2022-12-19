### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }

        if (s[0] == '}' || s[0] == '}' || s[0] == ')') {
            return false;
        }

        stack<char> st;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
                continue;
            }

            if (st.empty()) {
                return false;
            }

            if (c == ')' && st.top() == '(') {
                st.pop();
            } else if (c == ']' && st.top() == '[') {
                st.pop();
            } else if (c == '}' && st.top() == '{') {
                st.pop();
            } else {
                return false;
            }
        }
        
        return st.empty();
    }
};
```