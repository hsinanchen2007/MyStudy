根据 `n % 3` 的结果判断:
1. 结果为0, 直接返回 `3 ** (n / 3)`
2. 结果为 1,返回 `3 ** (n // 3 - 1) * 4`, 相当于拿出一个3和1组成4
3. 结果为 2, 则返回 `3 ** (n//3) * 2`

```python
class Solution:
    def cuttingRope(self, n: int) -> int:
        if n < 4:
            return n - 1
        lst = n % 3
        if lst == 1:
            return 3 ** (n // 3 - 1) * 4
        elif lst == 0:
            return 3 ** (n // 3)
        else:
            return 3 ** (n // 3) * lst
```