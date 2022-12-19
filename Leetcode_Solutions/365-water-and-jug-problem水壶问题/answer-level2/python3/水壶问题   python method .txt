### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if z==0 or z==x or z==y:
            return True
        
        if z> x+y:
            return False

        return z % math.gcd(x,y) == 0
```



最大公约数求解    

nice method for this problem,nice