### 解题思路
很简单

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0) return 0;
        if (x < 10) return 1;
        string s = to_string(x);
        for (int i = 0, j = s.length() - 1; i < j; i++, j--)
            if (s[i] != s[j]) return 0;
        return 1;
    }
};
```