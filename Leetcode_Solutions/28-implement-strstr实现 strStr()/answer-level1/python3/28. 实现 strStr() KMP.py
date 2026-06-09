左神代码python版。
```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle: return 0
        if not haystack: return -1
        n = len(haystack)
        m = len(needle)
        i = j = 0
        next = self.getNextArray(needle)
        while i < n and j < m:
            if haystack[i] == needle[j]:
                i += 1
                j += 1
            elif next[j] == -1:
                i += 1
            else:
                j = next[j]
        return i - j if j == m else -1
    def getNextArray(self, s):
        if len(s) == 1:
            return [-1]
        m = len(s)
        next = [0] * m
        next[0] = -1
        next[1] = 0
        cn = 0
        i = 2
        while i < m:
            if s[i-1] == s[cn]:
                cn += 1
                next[i] = cn
                i += 1
            elif cn > 0:
                cn = next[cn]
            else:
                next[i] = 0
                i += 1
        return next
```
