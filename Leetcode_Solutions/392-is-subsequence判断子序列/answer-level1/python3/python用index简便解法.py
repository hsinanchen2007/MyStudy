# python用index实现就很简单
```
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) > len(t):
            return False
        for str_0 in s:
            if str_0 not in t:
                return False
            else:
                i = t.index(str_0)
                t = t[i+1:]
        return True
```