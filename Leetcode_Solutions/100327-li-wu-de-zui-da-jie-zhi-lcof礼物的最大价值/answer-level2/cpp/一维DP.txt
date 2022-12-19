状态表示：`dp[i][j]`表示到达`i,j`位置处的最大价值
转移方程：`dp[i][j] = max{dp[i-1][j],dp[i][j-1]} + grid[i][j];`
dp数组初始状态：`dp[0][j] = {0}, dp[i][0] = {0}` （就是将第一行和第一列全部设为0）

其实这里的dp数组我们可以将它优化成一维的，优化之后的一维dp保存的是当前上一行的最大价值，然后我们从做到有去更新这个数组即可

![image.png](https://pic.leetcode-cn.com/169e622a32b24420ff5e50c1d857b8c92b488091d9948bc1cf3d0087893c6909-image.png)


```
int maxValue(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<int> dp(c+1,0);
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                dp[j+1] = max(dp[j],dp[j+1]) + grid[i][j];   
            }
        }
        return dp[c];
    }
```

时间复杂度：`O(N^2^)`
空间复杂度：`O(N)`
