### 解题思路
遍历替换

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == ' ') {
                res.append("%20");
            } else {
                res.append(string(1, s[i]));
            }
        }
        return res;
    }
};
```