### 解题思路
时间复杂度：O（1）
空间复杂度：O（1）

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        x0 = x
        x1 = 0.5 * (x0 + x / x0)
        while x0 != x1:
            x0 = x1
            x1 = 0.5 * (x0 + x / x0)

        return int(x1)
```