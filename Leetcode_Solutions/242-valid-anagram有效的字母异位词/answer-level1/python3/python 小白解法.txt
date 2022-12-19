```
from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        else:
            ss = Counter(s)
            tt = Counter(t)
            return ss == tt
```
