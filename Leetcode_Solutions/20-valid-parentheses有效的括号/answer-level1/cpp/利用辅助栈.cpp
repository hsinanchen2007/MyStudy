### 解题思路
利用辅助栈来处理，遇到左符号，入栈，遇到右符号，出栈。

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> symbol;
        for (char &s: s) {
            if (s == '(' || s == '[' || s == '{') {
                symbol.push(s);
            } else {
                if (symbol.empty()) {
                    return false;
                }
                if (s == ')' && symbol.top() != '(') {
                    return false;
                }
                if (s == ']' && symbol.top() != '[') {
                    return false;
                }
                if (s == '}' && symbol.top() != '{') {
                    return false;
                }
                symbol.pop();
            }
        }
        return symbol.empty();
    }
};
```