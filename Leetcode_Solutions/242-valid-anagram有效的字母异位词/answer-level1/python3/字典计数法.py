```
import collections
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        d=collections.defaultdict(int)
        for i in range(len(s)):
            d[s[i]]+=1
            d[t[i]]-=1
        for val in d.values():
            if val!=0:
                return False
        
        return True
```

