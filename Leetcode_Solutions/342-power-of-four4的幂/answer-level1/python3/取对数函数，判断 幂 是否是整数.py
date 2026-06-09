```
import math

class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num > 0:
            n = math.log(num, 4)
            if int(n) == n:
                return True
            else:
                False
        else:
            return False
```
