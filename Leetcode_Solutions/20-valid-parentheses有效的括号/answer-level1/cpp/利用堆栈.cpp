### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        int len = s.size();
        if (len % 2) return false;
        map<char, char> ind = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> res;
        res.push(s[0]);
        for (int pos = 1; pos < len; ++pos) {
            if (!res.empty() && ind[s[pos]] == res.top()) {
                res.pop();
            } else {
                res.push(s[pos]);
            }
        }

        return res.empty() ? true : false; 
    }
};
```