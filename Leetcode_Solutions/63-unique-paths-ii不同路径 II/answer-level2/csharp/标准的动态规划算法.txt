### 解题思路
使用了标准的动态规划算法，能通过，效率不太高。

执行用时 :112 ms, 在所有 C# 提交中击败了67.48%的用户
内存消耗 :24.7 MB, 在所有 C# 提交中击败了14.29%的用户

状态转移方程：
if(obstacleGrid[i][j]==1)
    ways[i,j]=0;
else
    ways[i,j]=ways[i-1,j]+ways[i,j-1];

### 代码

```csharp
public class Solution {
    public int UniquePathsWithObstacles(int[][] obstacleGrid) {
        int m=obstacleGrid.Length;
        int n=obstacleGrid.Length==0?0:obstacleGrid[0].Length;
        int[,] ways=new int[m,n];
        for(int i=0;i<m;i++)
        {
            if(obstacleGrid[i][0]==1)
            {
                ways[i,0]=0;
                break;
            }
            else
                ways[i,0]=1;
        }
        for(int i=0;i<n;i++)
        {
            if(obstacleGrid[0][i]==1)
            {
                ways[0,i]=0;
                break;
            }
            else
                ways[0,i]=1;
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                    ways[i,j]=0;
                else
                    ways[i,j]=ways[i-1,j]+ways[i,j-1];
            }
        return ways[m-1,n-1];
    }
}
```