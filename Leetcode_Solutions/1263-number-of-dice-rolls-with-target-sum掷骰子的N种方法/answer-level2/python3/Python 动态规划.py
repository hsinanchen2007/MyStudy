![image.png](https://pic.leetcode-cn.com/57c54db462e929704aa05916923de2df405cc537d7ce41da396fbcdd4e0ba944-image.png)


```
'''
dp(i, j) 表示i个骰子凑总和j的组合数
dp(i, j) = dp(i-1, j-1) + dp(i-1, j-2) + ...... dp(i-1, j-f)

'''

class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        dp = [[0 for _ in range(target + 1)] for _ in range(d+1)]

        for i in range(1, d+1):
            if i == 1:
                for j in range(1, min(target+1, f+1)):
                    dp[1][j] = 1

            else:
                for j in range(1, target+1):
                    ans = 0
                    for k in range(1, f+1):
                        if j - k >= 1:
                            ans += dp[i-1][j-k]
                        else:
                            break
                    dp[i][j] = ans % 1000000007
        return dp[d][target]
```
