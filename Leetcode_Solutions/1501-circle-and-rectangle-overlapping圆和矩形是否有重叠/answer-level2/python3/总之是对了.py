### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        import math
        x0=(x1+x2)/2
        y0=(y1+y2)/2
        lenx=(x2-x1)/2
        leny=(y2-y1)/2
        lnum=math.sqrt((x0-x_center)**2+(y0-y_center)**2)
        r1=math.sqrt(lenx**2+leny**2)
        if lnum>(r1+radius):
            return False
        elif abs(x0-x_center)<=(radius+lenx) or abs(y0-y_center)<=(radius+leny):
            return True
```