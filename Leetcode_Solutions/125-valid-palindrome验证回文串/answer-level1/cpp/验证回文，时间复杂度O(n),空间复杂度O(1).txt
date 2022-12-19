### 解题思路
快慢指针
### 代码

```cpp
class Solution {
public:
    // 48 - 57 0-9
    // 65 - 90 A-Z
    // 97 - 122 a-z
    char change(char c)
    {
        if((c >= 48 && c <= 57) || (c >= 97 && c <= 122))
        {
            return c;
        }
        if(c >= 65 && c <= 90)
        {
            return c + 32;
        }
        return 0;
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j)
        {
            char c1 = change(s[i]);
            char c2 = change(s[j]);
            if(c1 && c2)
            {
                if(c1 != c2)
                {
                    return false;
                }
                else
                {
                    ++i;
                    --j;
                }
            }
            else
            {
                if(!c1)
                {
                    ++i;
                }
                if(!c2)
                {
                    --j;
                }
            }
        }
        return true;
    }
};
```