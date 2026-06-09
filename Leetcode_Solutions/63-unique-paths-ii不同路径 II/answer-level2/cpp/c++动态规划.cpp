  - 动态规划
  - 如果遇到障碍，该位置值为0，否则为该位置左和上之和
```c++ []
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0][0]==1) return 0;
        vector<long> res(obstacleGrid[0].size()+1,0);
        for(int i=1;i<=obstacleGrid.size();i++){
            for(int j=1;j<=obstacleGrid[0].size();j++){
                if(i==1 && j==1) {res[j]=1-obstacleGrid[i-1][j-1];continue;}
                if(obstacleGrid[i-1][j-1]) res[j]=0;
                else res[j]+=res[j-1];
            }
        }
        return res[obstacleGrid[0].size()];
    }
};
```


