```
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        def calcMax(x, y):
            if x>y:
                x, y = y, x
            while y % x != 0:
                x, y = y%x, x
            return x
        if x*y == 0:
            return z==x or z==y
        m = calcMax(x, y)
        if z % m != 0:
            return False
        return z<=x+y
```
