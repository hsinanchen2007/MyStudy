```
class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt = collections.Counter(s)
        res = 0
        hasOdd = False
        for val in cnt.values():
            if val % 2 != 0:
                hasOdd = True
                val -= 1
            res += val  
        return res + 1 if hasOdd else res
```
