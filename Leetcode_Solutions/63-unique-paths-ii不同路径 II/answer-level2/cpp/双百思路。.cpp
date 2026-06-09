###1.考虑边界是否有障碍1，if有，该路径不通。2.其次就是中间的，同样的思路

此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
       vector<vector<long long>> dp(m, vector<long long>(n, 0));

        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]==0)
                dp[0][i]=1;
            else
                break;
        }
        for (int j=0;j<m;j++){
            if(obstacleGrid[j][0]==0)
                dp[j][0]=1;
            else
                break;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
```