```
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        from collections import Counter
        return list((Counter(t)-Counter(s)).elements())[0]
```