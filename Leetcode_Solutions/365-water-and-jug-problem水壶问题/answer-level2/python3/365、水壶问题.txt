写完后看下题解才知道数学上找到最大公约数就好了。
```
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if x == z or y == z or z == 0 or x + y == z:
            return True
        if x + y < z or x == 0 or y == 0:
            return False
        if x > y :
            x,y = y,x
        while y % x != 0 :
            x , y  = y % x , x
        if x > z :
            return False
        if (x + y) % z == 0 or z % (x + y) == 0 or z % y == 0 or z % x == 0:
            return True
        return False
```
