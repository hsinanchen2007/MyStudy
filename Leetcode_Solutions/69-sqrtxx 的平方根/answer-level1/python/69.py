### 解题思路
直接开方，取int类型结果。

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        sqrt_x = x ** 0.5
        return int(sqrt_x)
```