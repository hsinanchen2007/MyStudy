### 解题思路
左括号入栈、右括号匹配出栈，最后栈为空表示有效

### 代码

```cpp
class Solution {
public:
    bool isLeftParenthesis(char c) {
        return c == '(' || c == '[' || c == '{';
    }

    bool isRightParenthesis(char c) {
        return c == ')' || c == ']' || c == '}';
    }

    bool isPairs(char c1, char c2) {
        switch(c1) {
        case '(': return c2 == ')';
        case '[': return c2 == ']';
        case '{': return c2 == '}'; 
        }
        return false;
    }

    bool isValid(string s) {
        stack<char> chars;
        for (auto& c : s) {
            if (isLeftParenthesis(c)) {
                chars.push(c);
            }
            else if (isRightParenthesis(c)) {
                if (chars.empty() || !isPairs(chars.top(), c)) return false;
                chars.pop();
            }
        }
        return chars.empty();
    }
};
```