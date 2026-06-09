### 解题思路
动态规划的方法，设置状态变量dp[i,j]，表示到达(i,j)位置的路径个数，状态转移方程为dp[i,j]=dp[i-1,j]+dp[i,j-1]（因为上一个位置只能向右或向下），然后设置边界处的起始条件都是1，最后求dp[m-1,n-1]。

### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp={}
        for i in range(m):
            dp[i,0]=1
        for j in range(n):
            dp[0,j]=1
        for i in range(1,m):
            for j in range(1,n):
                dp[i,j]=dp[i,j-1]+dp[i-1,j]
        return dp[m-1,n-1]
```