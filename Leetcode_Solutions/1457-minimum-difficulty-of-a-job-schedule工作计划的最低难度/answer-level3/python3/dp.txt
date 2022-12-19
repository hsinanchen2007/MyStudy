### 解题思路
简单dp，dp[i][j]标识第i天完成前j项工作，dp[i][j] = max([dp[i-1][k] + max(jobDifficulty[k+1:j+1]) for k in range(i, j+1)])
返回最终的就行了。代码如下，很简单 

### 代码

```python3
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        if len(jobDifficulty)<d:
            return -1
        # dp = [[1e4]*len(jobDifficulty)]*d
        dp = []
        for i in range(d):
            dp.append([1e4]*len(jobDifficulty))
        for j in range(len(jobDifficulty)):
            dp[0][j] = max(jobDifficulty[:j+1])
        for i in range(1, d):
            for j in range(i, len(jobDifficulty)):
                for k in range(i, j+1):
                    dp[i][j] = min(dp[i][j], dp[i-1][k-1] + max(jobDifficulty[k:j+1]))
        return dp[d-1][len(jobDifficulty)-1]

```