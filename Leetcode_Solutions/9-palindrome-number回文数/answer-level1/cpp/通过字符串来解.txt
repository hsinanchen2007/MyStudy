### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string s = to_string(x);
        auto length = s.length();
        for(int i = 0; i < length; i++)
        {
            if(i >= length - 1 - i)
            {
                break;
            }
            if(s[i] != s[length - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};
```