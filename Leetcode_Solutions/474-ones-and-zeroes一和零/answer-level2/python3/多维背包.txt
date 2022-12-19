发现 0 和 1 的数量为价值，并且价值也是体积。所以开一个二维的 01 背包就搞定了。
整体没有什么坑。

```python
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        if len(strs) == 0:
            return 0
        dp = [[0 for _ in range(105)] for _ in range(105)]
        for s in strs:
            counter = dict(collections.Counter(s))
            _0s, _1s = counter.get('0', 0), counter.get('1', 0)
            for i in range(m, _0s - 1, -1):
                for j in range(n, _1s - 1, -1): 
                    dp[i][j] = max(dp[i][j], dp[i - _0s][j - _1s] + 1)
        return dp[m][n]
```