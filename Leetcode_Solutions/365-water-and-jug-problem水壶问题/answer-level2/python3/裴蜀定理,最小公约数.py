### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if x+y<z:
            return False
        if x==0 or y==0:
            return x==z or y==z or x+y==z
        g=math.gcd(x,y)
        if not g:
            return False
        return z%g==0

```