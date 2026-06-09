### 效率不高

执行用时 :
7468 ms, 在所有 Python3 提交中击败了5.02%的用户
内存消耗 :
13.7 MB, 在所有 Python3 提交中击败了20.48%的用户

### 思路

这个问题属于背包问题
1.先构造dp数组
2.找到状态转移方程
**状态转移方程为：dp[i]=min(dp[i-num(完全平方数)]+1,dp[i]])**

### 代码

```python3
class Solution(object):
    def numSquares(self, n):
        
        dp = [float('inf') for _ in range(n+1)]
        dp[0] = 0
        dp[1] = 1
        l = len(dp)
        for i in range(l):
            for j in range(int(i**0.5)+1):
                if i-j*j>=0:
                    dp[i] = min(dp[i],dp[i-j*j]+1)
        return dp[-1]
```