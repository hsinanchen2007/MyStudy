```
class Solution:
    def isUgly(self, num: int) -> bool:
        if num < 1:
            return False
            
        factors = [2,3,5]

        def helper(n):
            if n == 1:
                return True

            for f in factors:
                if n % f == 0 and helper(n // f):
                    return True
            
            return False

        return helper(num)
```
