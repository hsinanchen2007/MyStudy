思路见代码，挺简单的：
```
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        n = len(s)
        if n != len(t):
            return False
        m = dict()
        used = set()
        for i in range(n):
            if s[i] in m:
                if m[s[i]] != t[i]:
                    return False
            elif t[i] in used:
                return False
            m[s[i]] = t[i]
            used.add(t[i])
        return True
```
