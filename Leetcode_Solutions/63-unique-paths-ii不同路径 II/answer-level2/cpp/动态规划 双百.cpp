### 解题思路
[0][0]位置为1，直接结束。
第一行、第一列不但要考虑当前位置是否有障碍物，而且要考虑前位置是否可以访问。
### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector < vector <long>> dp (m,vector <long>(n,0));
        if (obstacleGrid[0][0]==1)
            return 0;
        dp[0][0]=1;
        for (int i=1;i<m;i++){
            if (obstacleGrid[i][0]==0 && dp[i-1][0]==1)  //当前位置没有障碍物，且上个位置可访问
                    dp[i][0]=1;
        }

        for (int j=1;j<n;j++) {
            if (obstacleGrid[0][j]==0 && dp[0][j-1]==1) //当前位置没有障碍物，且前个位置可访问。
                    dp[0][j]=1;
        }

        for (int i=1;i<m;i++){
            for (int j=1;j<n;j++){
                if (obstacleGrid[i][j]==0)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else
                    dp[i][j]=0;
            }
        }
    return dp[m-1][n-1];
    }
};
```