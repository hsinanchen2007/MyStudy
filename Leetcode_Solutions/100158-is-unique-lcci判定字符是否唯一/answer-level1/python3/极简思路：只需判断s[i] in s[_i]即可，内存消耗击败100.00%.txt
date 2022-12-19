
```
class Solution:
    def isUnique(self, astr: str) -> bool:
        for i in range(len(astr)):
            if astr[i] in astr[:i]:
                return False
        return True

```
