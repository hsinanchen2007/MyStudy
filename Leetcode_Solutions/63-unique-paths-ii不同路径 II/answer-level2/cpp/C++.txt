### 解题思路


### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if(obstacleGrid[0][0]==1) return 0;//判断（0，0），测试中有给出
        int m=obstacleGrid.size();//行
        int n=obstacleGrid[0].size();//列
        vector<vector<long>> result(m,vector<long>(n));
        result[0][0]=1;//result[i][j]是指从（0,0）到（i,j）的路径和
       for(int i=1;i<n;i++)
       {
           if(obstacleGrid[0][i]==0 && result[0][i-1]==1) result[0][i]=1;
           else result[0][i]=0;
       }
        for(int i=1;i<m;i++)
       {
           if(obstacleGrid[i][0]==0 && result[i-1][0]==1) result[i][0]=1;
           else result[i][0]=0;
       }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                result[i][j]=result[i-1][j]+result[i][j-1];
                //如果遇有障碍，则将此格的路径和清零，以免为后续经过此格的路线做贡献
                if(obstacleGrid[i][j]==1) result[i][j]=0;
            }
        }
        return result[m-1][n-1];
    }
};
```