### 解题思路

BFS

### 代码

```python []
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        q, v, ans = [amount], [True] * amount, 0
        while q:
            if 0 in q:
                return ans
            q = [
                v.__setitem__(j, False) or j
                for i in q
                for c in coins
                if (j := i - c) >= 0 and v[j]
            ]
            ans += 1
        return -1
```