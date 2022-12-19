对于每个字符，考虑两种情况，此字符最终状态为 0 或者 为 1，然后分别记录 0 和 1 的最少翻转次数，
遍历完成后取最小值即为最少翻转次数。

dp[i][0]，dp[i][1] 分别代表字符 S[i] 最终选择 0 和 1 的最少翻转次数，
考虑到递增，那么 dp[i][0] 只能由 dp[i-1][0] 转化而来，所以，状态转移方程如下：

- 如果 S[i] 是 '1':
      dp[i][0] = dp[i-1][0] + 1                 # 只能从 0 转化来，翻转 '1' 为 '0'，翻转次数加 1
      dp[i][1] = min(dp[i-1][0], dp[i-1][1])    # 已经为 '1'，无需翻转

- 如果 S[i] 是 '0':
      dp[i][0] = dp[i-1][0]                             # 只能从 0 转化来，无需翻转
      dp[i][1] = min(dp[i-1][0] + 1, dp[i-1][1] + 1)    # 翻转 '0' 为 '1'，翻转次数加 1

```python
class Solution:
    def minFlipsMonoIncr(self, S: str) -> int:
        zero, one = 0, 0
        for c in S:
            if c == '1':
                one, zero = min(zero, one), zero + 1
            else:
                one = min(zero + 1, one + 1)
        return min(zero, one)
```
