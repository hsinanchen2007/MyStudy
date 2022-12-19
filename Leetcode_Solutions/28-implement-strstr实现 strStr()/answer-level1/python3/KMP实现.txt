```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        
        # generate pnext
        i, k, m = 0, -1, len(needle)
        pnext = [-1] * m
        while i < m - 1:
            if k == -1 or needle[i] == needle[k]:
                i, k = i + 1, k + 1
                if needle[i] == needle[k]:
                    pnext[i] = pnext[k]
                else:
                    pnext[i] = k
            else:
                k = pnext[k]
        
        # matching
        h, j = 0, 0
        n = len(haystack)
        while h < m and j < n:
            if h == -1 or needle[h] == haystack[j]:
                h, j = h + 1, j + 1
            else:
                h = pnext[h]
        if h == m:
            return j - h
        return -1
```
