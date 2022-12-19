### 解题思路
先判断grid是否为空，为空则直接返回0。
开一个一维数组保存第一行累加的数据。
因为下一行只与上一行的数据相关，所以可以只用一维数组就好。
当j==0时为边界，左边没有数据，所以该位置等于上一行（自身）+该位置的数据。
当j>0时，左边和上边都有数据，所以该位置等于上一行（自身）和左边（前一个）的最小值+该位置的数据。
遍历完后dp[n-1]即为答案。

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        vector<int> dp(n);
        dp[0] = grid[0][0];
        for (int j=1; j<n; j++) dp[j] += dp[j-1] + grid[0][j];
        for (int i=1; i<m; i++) {
            dp[0] += grid[i][0];
            for (int j=1; j<n; j++) {
                dp[j] = min(dp[j-1],dp[j]) + grid[i][j];
            }
        }
        return dp[n-1];
    }
};
```