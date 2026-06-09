### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pS = 0;
        for(int i = 0; pS < s.length() && i < t.length(); i++) {
            if(s[pS] == t[i]) {
                pS++;
            }
        }
        return pS == s.length()? true:false;
    }
};
```