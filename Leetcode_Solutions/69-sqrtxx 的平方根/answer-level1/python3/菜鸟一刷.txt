### 解题思路
二分法，三个标记点，左区间，右区间，中间点
### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        if x==0:
            return 0
        if x<=3:
            return 1
        l=1
        r=x
        m=(x//2)
        while True:
            if m*m<=x and (m+1)*(m+1)>x:
                return m
            if m*m>=x:
                l=l
                r=m
                m=(l+r)//2
            else:
                l=m
                r=r 
                m=(l+r)//2


```