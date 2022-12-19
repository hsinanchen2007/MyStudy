记 ``A = {a, e, i, o, u}`` 分别计作，使用数组 valid[i][j] 表示 ``A[i]A[j]`` 是否符合规则。

使用 ``dp[k][i]`` 表示长度为 $k$ 的以 ``A[i]`` 结尾的序列个数。

```python
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        valid = [[0, 1, 0, 0, 0],
                 [1, 0, 1, 0, 0],
                 [1, 1, 0, 1, 1],
                 [0, 0, 1, 0, 1],
                 [1, 0, 0, 0, 0]]

        MOD = int(1e9) + 7
        dp = [[0]*5 for _ in range(n+1)]
        dp[1] = [1]*5

        for k in range(2, n+1):
            for i in range(5):
                for j in range(5):
                    if valid[i][j]:
                        dp[k][j] = (dp[k][j] + dp[k-1][i]) % MOD

        ret = 0
        for i in range(5):
            ret = (ret + dp[n][i]) % MOD

        return ret
```
