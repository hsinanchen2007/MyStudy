### 解题思路
递推公式还是上一题的
dp[i][j] = dp[i-1][j] + dp[i][j-1]
但是多了if(obstacleGrid[i-1][j] == 1)与if(obstacleGrid[i][j-1] == 1)的判断

此外要注意test case中，存在两个int相加越界的情况，因此我用了long

### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        if(obstacleGrid.back().back() == 1) return 0;
        int m = obstacleGrid[0].size(), n = obstacleGrid.size();
        vector<long> tmp(m, 0);
        vector<vector<long>> dp(n, tmp);
        dp[0][0] = 1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                //cout << i << " " << j << endl;
                if(i == 0 && j == 0) continue;
                long val1, val2;
                if(i == 0 || obstacleGrid[i-1][j] == 1){
                    val1 = 0;
                }else{
                    val1 = dp[i-1][j];
                }
                if(j == 0 || obstacleGrid[i][j-1] == 1){
                    val2 = 0;
                }else{
                    val2 = dp[i][j-1];
                }
                dp[i][j] = val1 + val2;
            }
        }
        return dp.back().back();
    }
};
```
###结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 85.70% 的用户 
内存消耗 : 7.1 MB , 在所有 C++ 提交中击败了 100.00% 的用户