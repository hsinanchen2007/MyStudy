### 解题思路
这题可以通过数学的贝祖定理来推出答案，ax + by = z，只要 ax + by = z且 z是xy的最大公约数的倍数就可以了。

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if x + y < z:
            return False
        if x == 0 or y == 0:
            return z == 0 or x + y == z
        return z % math.gcd(x, y) == 0
```