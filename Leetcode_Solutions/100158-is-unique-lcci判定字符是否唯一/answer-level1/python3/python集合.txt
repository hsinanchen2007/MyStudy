```
class Solution:
    def isUnique(self, astr: str) -> bool:
        a = set()
        for i in range(len(str)):
            if i in a:
                return False
            else:
                a.add(str)
```
