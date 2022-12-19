### 解题思路
动态规划常规解法，可以继续优化。重点为代码中文字描述部分。
其中dp[i]为for j in range(i)中的上一个j循环的最大值。

### 代码

```python3
class Solution:
    def cuttingRope(self, n: int) -> int:
        dp = [0 for i in range(n+1)]
        dp[1]=dp[2] = 1

        for i in range(3,n+1):
            for j in range(i):

                #分成两段，两端继续减，i-j继续分，j继续分，dp[i]为上一次循环j得到的最大值。
                dp[i] = max((i-j)*j,dp[i-j]*dp[j],dp[i-j]*j,(i-j)*dp[j],dp[i])
                
        return dp[-1]
```