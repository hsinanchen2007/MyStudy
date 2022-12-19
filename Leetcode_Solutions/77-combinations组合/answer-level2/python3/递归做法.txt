返回 1 ... n 中所有可能的 k 个数的组合， 等价于：

n + 返回 1 ... n-1 中所有可能的 k-1 个数的组合.

```
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        if k > n:
            return []
        if k == n:
            return [list(range(1, n+1))]
        if k == 1:
            return [[i] for i in range(1, n+1)]
        result = []
        for i in range(n, k-1, -1):
            res = self.combine(i-1, k-1)
            for r in res:
                result.append([i] + r)
        return result
```
