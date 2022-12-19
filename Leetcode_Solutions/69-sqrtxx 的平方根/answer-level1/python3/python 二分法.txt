python 二分法
```
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:#取值为0的边界情况
            return 0
        else:#二分法
            low = 1
            high = (x+1)//2+1#由于要求的数不可能在原数的一半以上，一定在(x+1)//2+1左边
            while low <= high:
                mid = (low + high) // 2
                if mid ** 2 > x:
                    high = mid -1
                elif (mid ** 2 < x) & ((mid + 1)** 2 <= x):
                    low = mid + 1
                elif (mid ** 2 < x) & ((mid + 1)** 2 > x):#不能完全平方的情况
                    return mid
                elif mid ** 2 == x:#完全平方的情况
                    return mid

```
