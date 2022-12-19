### 解题思路
感觉有点不严谨

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        return x+y>=z and (z==0 or y and z%math.gcd(x,y)==0)
```