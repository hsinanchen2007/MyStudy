**时间复杂度O(nr)**
**空间复杂度O(n)**
```
class Solution:
    def rotatedDigits(self, N: int) -> int:
        return len([good for good in range(2, N+1) 
                   if len([i for i in str(good) if i in ('2', '5', '6', '9')]) and
                      not len([i for i in str(good) if i in ('3', '4', '7')])])
```