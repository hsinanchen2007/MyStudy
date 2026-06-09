这题用二维动态规划，注意当数组的维度很大时，结果会超过int能表示的最大值，所以结果数组用long long类型
代码如下：
```
class Solution {
public:
    long long path[101][101];
    Solution()
    {
        memset(path,0,sizeof(path));
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int len1=obstacleGrid.size();
        if(len1==0)
            return 0;
        if(len1==1)
        {
            for(int i=0;i<obstacleGrid[0].size();i++)
            {
                if(obstacleGrid[0][i]==1)
                    return 0;
            }
            return 1;  
        }
        int len2=obstacleGrid[0].size();
        if(len2==1)
        {
            for(int i=0;i<len1;i++)
            {
                if(obstacleGrid[i][0]==1)
                    return 0;
            }
            return 1;
        }
        bool flag=false;
        for(int i=0;i<obstacleGrid[0].size();i++)
        {
            if(flag==false && obstacleGrid[0][i]!=1)
                path[0][i]=1;
            else if(flag==false && obstacleGrid[0][i]==1)
            {
                path[0][i]=0;
                flag=true;
            }
            else
                path[0][i]=0;
        }
        flag=false; 
        for(int i=0;i<len1;i++)
        {
            if(flag==false && obstacleGrid[i][0]!=1)
                path[i][0]=1;
            else if(flag==false && obstacleGrid[i][0]==1)
            {
                path[i][0]=0;
                flag=true;
            }
            else
                path[i][0]=0;
        }  
        for(int i=1;i<len1;i++)
            for(int j=1;j<len2;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    path[i][j]=0;
                    continue;
                }
                path[i][j]=path[i-1][j]+path[i][j-1];
            }
        if(path[len1-1][len2-1]==-1)
            return 0;
        else 
            return path[len1-1][len2-1];
    }
};
```

