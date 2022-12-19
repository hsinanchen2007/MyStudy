### 解题思路
对半查找没了

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        i, j = 1, x
        #对半查找
        mid = ((i+j)//2)
        while 1:
            if mid**2 > x:
                j = mid
                mid = ((i+j)//2)
            elif mid**2 < x and (mid+1)**2 < x :
                i = mid
                mid = ((i+j)//2)
            elif mid**2 == x or( mid**2 < x and (mid+1)**2 > x ):
                return mid
            elif (mid+1)**2 == x:
                return mid+1
        #试试 梯度下降
```