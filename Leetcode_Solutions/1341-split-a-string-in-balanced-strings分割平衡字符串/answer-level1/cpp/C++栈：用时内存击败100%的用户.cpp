### 解题思路
代码有点长，但是逻辑简单。

### 代码

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        string res;
        char c = NULL;
        int ans = 0;
        while (s.size()) {
            c = s.back();
            s.pop_back();
            if (res.empty()) {
                res.push_back(c);
            }
            else if(res.back() == 'L') {
                if (c == 'R') {
                    res.pop_back();
                    if (res.empty()) {
                        ans += 1;
                        res = "";
                    }
                }
                else {
                    res.push_back(c);
                }
            }
            else {
                if (c == 'R') {
                    res.push_back(c);
                }
                else {
                    res.pop_back();
                    if (res.empty()) {
                        ans += 1;
                        res = "";
                    }
                }
            }   
        }
        return ans;
    }
};
```