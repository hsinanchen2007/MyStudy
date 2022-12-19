### 解题思路
在这道题中，因为只能往下或者往右走那就很简单了，我们只需要将边界值控制好就行了。
首先我们先定义一个dp数组来存储到达每一个格的走法，注意这里dp中的值要定义为long int 类型否则当数组很大的时候int 可能存储不下。
1.在第一行的时候我们只需要判断这个格里值是否为1，若是则这个个值置为0，否者等于前一个的格值，第一列的情况也同理
2.当i!=0&&j!=0的时候我们只需要判断这个格是否为1，若是则置为0，否则到达这个格的走法就是它的上边的格和左边的格走法的和。
### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<long int>>dp(m,vector<long int>(n,0));
      dp[0][0]=obstacleGrid[0][0]==1?0:1; //初始化0行0列，作为基准值，以这个格填写整张表格
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j!=0) //第一行的时候
                {
                    if(obstacleGrid[i][j]!=1)
                    {
                        dp[i][j]=dp[i][j-1];
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
               else if(j==0&&i!=0)//第一列的时候
                {
                    if(obstacleGrid[i][j]!=1)
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
                else if(i!=0&&j!=0) //表示第一行，第一列的时候
                {
                    if(obstacleGrid[i][j]==1)
                    {
                        dp[i][j]=0;
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    }
                }
            }
        }
          return dp[m-1][n-1];
    }
};
```