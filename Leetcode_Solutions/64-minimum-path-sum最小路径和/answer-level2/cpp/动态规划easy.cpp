### 解题思路
这题也是非常简单的，在这里简单的说一下思路：
在第一行和第一列的时候，我们只需要加上这个格的前一个格的值即可，即是到达这个格的最短距离，
当某一个格不是第一行，或第一列的时候，我们应该比较一下这格的上边和左边比较出最小的值，然后加在当前格中。

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
           int m=grid.size();
           int n=grid[0].size();
           for(int i=0;i<m;i++)
           {
               for(int j=0;j<n;j++)
               {
                   if(i==0&&j!=0)
                   {
                       grid[i][j]+=grid[i][j-1];
                   }
                   else if(j==0&&i!=0)
                   {
                       grid[i][j]+=grid[i-1][j];
                   }
                   else if(i!=0&&j!=0)
                   {
                       grid[i][j]+=(grid[i-1][j]>grid[i][j-1]?grid[i][j-1]:grid[i-1][j]);
                   }
               }
           }
           return grid[m-1][n-1];
    }
};
```