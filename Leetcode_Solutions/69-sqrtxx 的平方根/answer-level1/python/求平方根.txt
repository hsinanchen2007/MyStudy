根据题意返回值为整数的求解方式
```
class Solution:
    def mySqrt(self, x: int) -> int:
        low = 0
        high = x // 2 + 1
        
        while low < high:
            mid = (low + high + 1) // 2
            if mid ** 2 > x:
                high = mid - 1
            else:
                low = mid
        return low
```

要求误差再error内的求解方式
```
def sqrt(x, error):
    low = 0
    high = x / 2 + 1
    mid = (low + high) / 2
    while high - low > error:
        if mid ** 2 > x:
            high = mid
        else:
            low = mid
        mid = (low + high) / 2
    return mid
```
