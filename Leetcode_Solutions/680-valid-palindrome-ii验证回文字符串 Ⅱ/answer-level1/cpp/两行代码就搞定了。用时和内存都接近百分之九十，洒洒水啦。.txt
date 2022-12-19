### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool validPalindrome(string s) {
        int L = 0;
        int R = s.size() - 1;
        int sin = 0;
        while(L < R)
        {
            if(s[L] != s[R])
            {
                if(sin > 0)
                {
                    return 0;
                }
                if(s[L + 1] != s[R] && s[L] != s[R - 1])
                {
                    return 0;
                }
                if(s[L] == s[R - 1] && s[L + 1] == s[R])
                {
                    if(s[L + 2] == s[R - 1])
                    {
                        L++;
                        sin++;
                    }
                    else if(s[L + 1] == s[R - 2])
                    {
                        R--;
                        sin++;
                    }
                }
                else if(s[L] == s[R - 1])
                {
                    R--;
                    sin++;
                }
                else if(s[L + 1] == s[R])
                {
                    L++;
                    sin++;
                }

            }
            L++;
            R--;
        }
        return 1;
    }
};
```