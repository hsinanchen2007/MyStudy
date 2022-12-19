### 解题思路

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        m, n, find = 0, 0, 0
        while m < len(s) and n < len(t):
            if s[m] == t[n]:
                find += 1
                m += 1
            n += 1
        return find == len(s)
```