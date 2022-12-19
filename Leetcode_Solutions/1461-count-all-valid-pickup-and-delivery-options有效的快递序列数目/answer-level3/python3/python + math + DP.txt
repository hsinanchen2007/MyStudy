```python
class Solution:
    def countOrders(self, n: int) -> int:
        # pickup(i) -> delivery(i)
        # mathmatic problem + dp
        # Time complexity: O(N)
        # Space complexity: O(1)
        mod = 1e9 + 7
        res = 1
        if n == 1: return 1
        for i in range(2, n + 1):
            res = (res * i * (2 * i - 1)) % mod
        return int(res)
```