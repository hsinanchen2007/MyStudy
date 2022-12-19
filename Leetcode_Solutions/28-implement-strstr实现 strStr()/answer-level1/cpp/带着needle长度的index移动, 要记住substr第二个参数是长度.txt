### 解题思路
从左往右, 一个for loop可以搞定

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int r = needle.length();

        if (n < r) return -1;
        else if (n == 0 && r == 0) return 0;

        for (int i = 0; i <= n - r; ++i)
        {
            if (haystack.substr(i, r) == needle) return i;
        }

        return -1;
    }
};
```