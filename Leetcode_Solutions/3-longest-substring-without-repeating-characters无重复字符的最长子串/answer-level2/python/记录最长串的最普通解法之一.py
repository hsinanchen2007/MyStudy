
```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxlen = 0
        l = []
        curlen = 0
        for i in s:
            if i not in l:
                l.append(i)
            else:
                curlen = len(l)
                if maxlen<=curlen:
                    maxlen = curlen
                l = l[l.index(i)+1:]
                l.append(i)
        curlen = len(l)
        return curlen if maxlen < curlen else maxlen
```
