### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n == 0) return true;
        std::stack<char> charStack;

        for (int i = 0; i < n; ++i)
        {
            if (!charStack.empty() && ((s[i] == ')' && charStack.top() == '(') ||(s[i] == '}' && charStack.top() == '{') \
                || (s[i] == ']' && charStack.top() == '[')))
            {
                charStack.pop();
            }
            else
            {
                charStack.push(s[i]);
            }
        }

        return charStack.empty();
    }
};
```