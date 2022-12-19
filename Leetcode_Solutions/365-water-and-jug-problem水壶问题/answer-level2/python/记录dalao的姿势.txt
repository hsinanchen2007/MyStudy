
### 代码
```python
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if z==0:return True
        if z > x+y :return False
        x,y = (x,y) if x<y else (y,x)
        if x==0:return y==z
        while y%x != 0:
            y,x = x,y%x
        return z%x == 0
```