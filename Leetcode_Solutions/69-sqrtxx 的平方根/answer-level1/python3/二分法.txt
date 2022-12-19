### 解题思路
二分法，low，high

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        if x==0:return 0
        low=1
        high=x
        while high-low>1:
            medium=low+(high-low)//2
            result=medium*medium
            if result==x:
                return medium
            elif result>x:
                high=medium
            else:
                low=medium
        return low
```