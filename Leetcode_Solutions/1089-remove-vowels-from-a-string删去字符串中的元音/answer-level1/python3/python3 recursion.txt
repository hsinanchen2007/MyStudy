```
class Solution:
    def removeVowels(self, S: str) -> str:
        l = ['a', 'e', 'i', 'o', 'u']
        i = 0
        def removechar(ss, i):
            if i == len(l):
                return ss
            return removechar(ss.replace(l[i], ''), i+1)
            
        return removechar(S, i)
            
```

