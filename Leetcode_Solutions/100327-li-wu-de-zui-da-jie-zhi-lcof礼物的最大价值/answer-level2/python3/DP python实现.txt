![image.png](https://pic.leetcode-cn.com/9cbd37315021096d446d776622a5ceba40b49f674f8243519809917d82579c60-image.png)


### 代码

```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        #动态规划，贪心算法
        num_r=len(grid)
        num_c=len(grid[0])
        #dp[i][j]走到i，j拿到的礼物价格
        dp=grid
        for j in range(1,num_c):
            dp[0][j]+=dp[0][j-1]
        for i in range(1,num_r):
            dp[i][0]+=dp[i-1][0]
        for i in range(1,num_r):
            for j in range(1,num_c):
                dp[i][j]=max(dp[i][j-1],dp[i-1][j])+grid[i][j]
        return (dp[num_r-1][num_c-1])

```