### 解题思路
见代码。

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        string ans;
        while (!s.empty()) {
            char t = s.back();
            char p;
            ans.empty() ? p = NULL : p = ans.back();
            if (t == '(' && p == ')') {
                ans.pop_back();
            }
            else if (t == '[' && p == ']') {
                ans.pop_back();
            }
            else if (t == '{' && p == '}') {
                ans.pop_back();
            }
            else {
                ans.push_back(t);
            }
            s.pop_back();
        }
        return ans.empty();
    }
};
```