### 解题思路
没有思路

### 代码

```python3
class Solution:
    def numWays(self, n: int) -> int:
        if n == 0:
            return 1
        if n== 1:
            return 1
        res = [0 for _ in range(n)]
        res[0] = 1
        res[1] = 2
        for i in range(2, n):
            res[i] = res[i-1] + res[i-2]
        return res[n-1] % (1000000007)
```