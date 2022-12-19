### 解题思路
用俩指针left和right，每次判断s[left : right-1]中是否有和s[right]相等的。
如果有，从left+1开始算（因为s[left]已经不用看了），right++即可。

### 代码

```cpp
class Solution {
public:
    int conflict(string& s, int l, int r) {
        while (l < r) {
            if (s[l] == s[r]) return l;
            l++;
        }
        return -1;
    }

    int lengthOfLongestSubstring(string s) {
        int slen = s.length();
        if (slen < 2) return slen;
        int left = 0, right = 1, ans = 1, tmp = 0;
        while (right < slen) {
            tmp = conflict(s, left, right);
            if (tmp == -1) {
                right++;
                ans = (right-left) > ans ? right-left : ans;
            } else {
                left = tmp + 1;
                right++;
            }
        }
        return ans;
    }
};
```