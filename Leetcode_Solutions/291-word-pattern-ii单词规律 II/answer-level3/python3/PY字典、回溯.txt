```
class Solution:
    def wordPatternMatch(self, p: str, s: str,d={},v=set(),i=0,j=0) -> bool:
        if i == 0 and j == 0:
            d.clear()
            v.clear()
        if i == len(p) and j == len(s):
            return True
        if not s or not p or i == len(p) or j == len(s):
            return False
        if p[i] in d:
            w = d[p[i]]
            return s[j:j + len(w)] == w and self.wordPatternMatch(p, s, d, v, i + 1, j + len(w))
        for k in range(j + 1, len(s) + 1):
            w = s[j:k]
            if w not in v:
                d[p[i]] = w
                v.add(w)
                if self.wordPatternMatch(p, s, d, v, i + 1, k):
                    return True
                del d[p[i]]
                v.remove(w)
        return False
```
