### 解题思路
从最后一个配送开始考虑问题。一行完事

### 代码

```python3
class Solution:
    def countOrders(self, n: int) -> int:
        return (n*self.countOrders(n-1)*(2*n-1))%(10**9+7) if n>2 else [1,6][n-1]
```