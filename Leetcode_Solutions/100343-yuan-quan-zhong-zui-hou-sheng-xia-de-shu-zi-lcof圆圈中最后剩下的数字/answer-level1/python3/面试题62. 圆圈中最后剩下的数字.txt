### 解题思路

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        ans = [i for i in range(0, n)]
        cn = 0
        while n > 1:
            ind = m%n + cn-1
            if ind >= n: ind -= n
            elif ind == -1: ind = n - 1
            cn = ind
            ans.pop(ind)
            n -= 1
        return ans[0]

```