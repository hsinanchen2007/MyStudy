```
import math
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num <= 5:
            return False
        sum, l, r = 0, 1, math.sqrt(num)
        while l < r:
            if num % l == 0:
                sum = sum + l
                if num / l != num:
                    sum = sum + num / l
            l = l + 1
        return num == sum
```
