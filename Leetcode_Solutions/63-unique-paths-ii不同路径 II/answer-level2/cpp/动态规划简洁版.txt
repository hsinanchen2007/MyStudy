## 希望大家多看看我的
## 写的很简洁了

>采用的方法也是动态规划，
>首先确定上面和左边的边界情况，
>然后根据v[i][j]=v[i-1][j]+v[i][j-1]进行拓展，注意如果该点有障碍，就直接置为0

<br>
----
```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0 || obstacleGrid[0].size()==0)
            return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<long>> v(m,vector<long>(n));
        v[0][0]=!obstacleGrid[0][0];
        for(int i=1; i<m; i++) v[i][0] = (obstacleGrid[i][0]||v[i-1][0]==0)?0:1;
        for(int i=1; i<n; i++) v[0][i] = (obstacleGrid[0][i]||v[0][i-1]==0)?0:1;
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                v[i][j]=obstacleGrid[i][j]?0:v[i-1][j]+v[i][j-1];
        return v[m-1][n-1];
    }
};
```