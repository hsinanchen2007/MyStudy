```
class Solution:
    def isUnique(self, astr: str) -> bool:
        a=collections.Counter()
        for i in astr:
            if a[i]==0:
                a[i]=1
            else:
                return False
        return True
```
