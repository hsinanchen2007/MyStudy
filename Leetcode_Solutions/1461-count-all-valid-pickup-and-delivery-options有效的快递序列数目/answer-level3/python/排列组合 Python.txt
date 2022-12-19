比如有 3 个快递
那么有6个位置
收发顺序是固定的
思路就是
6个位置里面选择2个位置
剩下4个位置里面选择2个位置
剩下2个位置里面选择2个位置

```python
class Solution:
    def countOrders(self, n: int) -> int:
        from scipy.special import comb
        n = 2 * n
        res = 1
        while n >= 2:
            res *= comb(n, 2)
            res = int(res) % (10 ** 9 + 7)
            n -= 2
        return res
```
