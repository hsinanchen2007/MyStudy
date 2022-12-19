### 解题思路

从中心展开判断两边是否对称，中心有可能是某个点（奇数长度），或者是两点之间（偶数长度）


### 代码

```cpp
class Solution {
public:
    int expand(string s, int left, int right) {
        int l = left, r = right;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }

    string longestPalindrome(string s) {
        if (s.length() < 1) return s;
        int len = s.length();
        int start = 0, maxLen = 0;
        for (int i = 0; i < len; i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            int tmp = max(len1, len2);
            if (maxLen < tmp) {
                maxLen = tmp;
                start = i - (tmp - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};
```