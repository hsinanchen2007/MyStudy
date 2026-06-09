### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            for (j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};
```其实挺不容易的，看起来简单，但是实施起来、判断条件都不是容易一次性就能设置对的，尤其是边界条件的判断，仔细体会还真是精妙。