### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      if(grid.size()==0)return 0;
      int x=0;int z=0;
      for(int i=0;i<grid.size();i++)
      {
         for(int j=0;j<grid[0].size();j++)
         {
             if(grid[i][j]==1)
             {
              x=getArea(grid,i,j);
             }
             z=max(z,x);
         }
      }
      return z;
    }
    int getArea(vector<vector<int>>&grid,int i,int j)
    {   if(i==grid.size()||i<0)return 0;
        if(j==grid[0].size()||j<0)return 0;
        if(grid[i][j]==1)
        {
            grid[i][j]=0;
            return 1+getArea(grid,i+1,j)+getArea(grid,i-1,j)+getArea(grid,i,j-1)+getArea(grid,i,j+1);
        }
        return 0;
    }
};
```