### 解题思路
使用栈解题

### 代码

```cpp
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> sta;
        sta.push(0);
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                sta.push(0);
            }
            if (S[i] == ')') {
                int v = sta.top();
                sta.pop();
                int w = sta.top();
                sta.pop();
                sta.push(w + max(2 * v, 1));
            }
        }
        return sta.top();
    }
};
```