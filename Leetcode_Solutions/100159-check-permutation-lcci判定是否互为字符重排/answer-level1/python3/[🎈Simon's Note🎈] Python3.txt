```
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        from collections import Counter
        c1=Counter(s1)
        c2=Counter(s2)
        if c1.keys()!=c2.keys():
            return False
        else:
            for k in c1.keys():
                if c1[k]!=c2[k]:
                    return False
        return True
```
