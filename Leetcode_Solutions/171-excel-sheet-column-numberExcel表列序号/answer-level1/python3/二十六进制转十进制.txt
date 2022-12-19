执行用时 :48 ms, 在所有 Python3 提交中击败了96.90% 的用户。
内存消耗 :13.1 MB, 在所有 Python3 提交中击败了84.61%的用户。

```
class Solution:
    def titleToNumber(self, s: str) -> int:
        val = 0
        l = len(s)
        for i in range(l):
            tmp = ord(s[i]) - 64
            val += tmp * 26**(l-1-i)
        return val
```