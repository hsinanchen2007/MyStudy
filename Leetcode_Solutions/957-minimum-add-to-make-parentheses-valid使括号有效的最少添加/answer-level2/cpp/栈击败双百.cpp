### 解题思路
栈击败双百

### 代码

```cpp
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> sta;
        for (string::iterator it = S.begin(); it != S.end(); it++) {
            if (*it == ')' && !sta.empty() && sta.top() == '(') {
                sta.pop();
            }
            else {
                sta.push(*it);
            }
        }
        return sta.size();
    }
};
```