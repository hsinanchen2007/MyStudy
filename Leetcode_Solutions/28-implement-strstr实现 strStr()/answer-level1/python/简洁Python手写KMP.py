### 解题思路
KMP算法

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        if not haystack or len(needle) > len(haystack):
            return -1
        i1 = 0
        i2 = 0
        next = self.getNextArray(needle)
        while i1 < len(haystack) and i2 < len(needle):
            if haystack[i1] == needle[i2]:
                i1 += 1
                i2 += 1
            else:
                if next[i2] == -1: # i2来到needle的零位置
                    i1 += 1 # 此时i1来needle的零位置都无法匹配，只能自加
                else:
                    i2 = next[i2]
        return i1 - len(needle) if i2 == len(needle) else -1
    
    def getNextArray(self, p):
        if len(p) == 1:
            return [-1]
        next = [None] * len(p)
        next[0] = -1
        next[1] = 0
        i = 2
        X = 0
        while i < len(next):
            if p[i -1] == p[X]:
                next[i] = X + 1
                i += 1
                X += 1
            elif X > 0:
                X = next[X]
            else:
                next[i] = 0
                i += 1
        return next
```