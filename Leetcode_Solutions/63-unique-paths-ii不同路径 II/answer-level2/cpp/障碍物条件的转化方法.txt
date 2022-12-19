### 解题思路
本题与62题唯一的区别在于障碍物，这里认为只要(i, j)处有障碍物，则dp[i][j] = 0;状态转移方程和62题如出一辙
代码中1,2,3是写代码过程中犯的低级错误。
然后本题也可以使用滚动数组的方法降低空间复杂度到O(n)，代码中没有体现。


### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        if(obstacleGrid[0][0] == 1) return 0;
        int n = obstacleGrid[0].size();
        // 3. 最后结果可能很大
        vector<vector<unsigned long long>> dp(m, vector<unsigned long long>(n, 0));
        // 这里默认如果障碍物就是终点，则为0;
        dp[0][0] = 1;
        // 1.两个循环m, n写反了
        // 2.应该是dp[0][j - 1]不是直接为1
        for(int j = 1; j < n; j++) {
            dp[0][j] = obstacleGrid[0][j] ? 0 : dp[0][j - 1];
        }
        for(int i = 1; i < m; i++) {
            dp[i][0] = obstacleGrid[i][0] ? 0 : dp[i - 1][0];
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j])
                    dp[i][j] = 0;
                else {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
```
![图片.png](https://pic.leetcode-cn.com/41dbeb03ea89b00cd3bf1808d2d35350a86005a5580789ad43891d66150d2531-%E5%9B%BE%E7%89%87.png)
