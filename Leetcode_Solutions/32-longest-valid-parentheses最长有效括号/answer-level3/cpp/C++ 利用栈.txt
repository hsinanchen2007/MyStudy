### 解题思路
括号配对自然想到栈操作

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stc;
        int res = 0;
        int size = s.size();
        int start = 0;

        stc.push(-1);
        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                stc.push(i);
            } else {
                stc.pop();
                if (stc.empty()) {
                    stc.push(i);
                } else {
                    res = max(res, i - stc.top());
                }
            }
        }
        return res;       
    }
};
```