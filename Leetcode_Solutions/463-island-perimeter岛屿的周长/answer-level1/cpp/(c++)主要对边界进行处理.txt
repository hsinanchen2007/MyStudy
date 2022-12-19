执行用时 :84 ms, 在所有 C++ 提交中击败了92.46% 的用户
内存消耗 :16 MB, 在所有 C++ 提交中击败了90.52%的用户
```
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
       int sum=0;
       for(int i=0;i<grid.size();i++)
       {
           for(int j=0;j<grid[0].size();j++)
           {
               if(grid[i][j]==1)
               {
                   sum+=4;
               if(i>0&&grid[i-1][j]==1) sum-=1;
               if(i<grid.size()-1&&grid[i+1][j]==1)sum-=1;
               if(j>0&&grid[i][j-1]==1)sum-=1;
               if(j<grid[0].size()-1&&grid[i][j+1]==1)sum-=1;
               }
           }
       }
       return sum;
    }
};
```
