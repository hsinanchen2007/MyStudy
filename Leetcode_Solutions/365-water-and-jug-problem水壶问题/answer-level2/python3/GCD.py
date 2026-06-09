### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        import math
        if x + y < z:
            return False
        if z == 0:
            return True
        if x == 0:
            return y == z
        if y == 0:
            return x == z
        
        return z % math.gcd(x, y) == 0

```