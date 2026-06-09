```python
class Solution:
    def mySqrt(self, x: int) -> int:
        r = x
        while r*r > x: r = (r + x/r) // 2
        return int(r)
```
- 基本不等式(a+b)/2 >=√ab 推导自 (a-b)^2 >= 0，注意 a>0 且 b>0
- r 代表 result

```python
class Solution:
    def mySqrt(self, x: int) -> int:
        l, h = 0, x
        while l < h:
            m = (l + h) // 2
            if m**2 <= x < (m+1)**2:
                return m
            elif m**2 < x:
                l = m + 1
            else:
                h = m - 1
        return l
```
- 二分搜索