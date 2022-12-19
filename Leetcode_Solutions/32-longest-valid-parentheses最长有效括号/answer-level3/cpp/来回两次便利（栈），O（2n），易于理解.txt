### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int result = 0;
        stack<int> msk;
        int cur = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') msk.push(1);
            if (s[i] == ')') {
                if (!msk.empty()) {
                    msk.pop();
                    cur += 2;
                    if (msk.empty()) {
                        result = cur > result ? cur : result;
                    }
                }
                else {
                    result = cur > result ? cur : result;
                    cur = 0;
                }
            }
            
        }
        cur = 0;
        stack<int>msk2;
        for (int i = len - 1; i > 0; i--) {
            if (s[i] == ')') msk2.push(1);
            if (s[i] == '(') {
                if (!msk2.empty()) {
                    msk2.pop();
                    cur += 2;
                    if (msk2.empty()) {
                        result = cur > result ? cur : result;
                    }
                }
                else {
                    result = cur > result ? cur : result;
                    cur = 0;
                }
            }
        }
        return result;
    }
};
```