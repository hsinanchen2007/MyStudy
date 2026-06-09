```
from collections import Counter
class Solution:
    def hasGroupsSizeX(self, deck) -> bool:
        def gcd(a,b):
            if a>=b:
                return gcd(b,a%b) if a%b else b
            else:
                return gcd(a,b%a) if b%a else a

        nums = list(Counter(deck).values())
        if len(deck) == 1:
            return False
        if nums.__len__()==1:
            if nums[0]>=2:
                return True
            else:
                return False
        rf = gcd(nums[0], nums[0 + 1])
        for i in range(2,len(nums)):
            rf = gcd(rf,nums[i])
            if rf == 1:
                return False
        return True
```