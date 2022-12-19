### 解题思路
直接算，但是pyton3有collection，可以简化程序。

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        tmp = {}
        ret = 0
        for i in range(len(s)):
            key = s[i]
            if key in tmp.keys():
                tmp[key] += 1
            else:
                tmp[key] = 1
            if tmp[key] == 2:
                ret += 2
                tmp[key] = 0
        if 1 in tmp.values():
            ret += 1
        return ret



```