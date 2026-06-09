### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lenS = s.size(), lenT = t.size();
        int i = 0, j = 0;
        while(i < lenS && j < lenT)
        {
            if(s[i] == t[j])
            {
                ++i;
                ++j;
            }
            else
                ++j;
        }
        return i == lenS;
    }
};
```