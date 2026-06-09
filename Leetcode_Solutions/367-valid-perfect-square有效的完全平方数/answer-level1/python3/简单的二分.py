```
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        l, r = 0, num
        while l < r:
            m = l + r >> 1
            if m**2 < num:
                l = m + 1
            else:
                r = m
        return l**2 == num  
```
先找出刚好大于等于sqrt(num)的整数，再判断这个整数是不是刚好是sqrt(num)
