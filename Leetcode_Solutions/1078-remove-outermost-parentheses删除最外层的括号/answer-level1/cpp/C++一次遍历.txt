### 解题思路
记录当前深度，处理左括号时后更新深度，处理右括号时先更新深度。

### 代码

```cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int depth = 0;
        for (char c : S) {
            if (c == '(') {
                if (depth > 0)
                    ans.push_back(c);
                depth++;
            } else {
                depth--;
                if (depth > 0)
                    ans.push_back(c);
            }
        }
        return ans;
    }
};
```