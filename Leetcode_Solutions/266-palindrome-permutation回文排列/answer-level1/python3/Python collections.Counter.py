```
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        d=dict(collections.Counter(s))
        once=False
        for i in d.values():
            if i%2==1:
                if once:
                    return False
                once=True
        return True
```
