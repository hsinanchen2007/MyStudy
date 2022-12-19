```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int p = 0;
        stack<int> stack;
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == '(') stack.push(i);
            else if (s[i] == ')') {
                if (stack.empty()) p = i + 1;
                else {
                    stack.pop();
                    res = stack.empty() ? max(res, i - p + 1) : max(res, i - stack.top());
                }
            }
        }
        return res;
    }
};
```
