### 解题思路
递归方法 还是很好理解的
![批注 2020-03-15 083929.png](https://pic.leetcode-cn.com/1ca72d1a48bee104c656aa142439b65852081a5d5e6ec56bea231a6f9a02b080-%E6%89%B9%E6%B3%A8%202020-03-15%20083929.png)

### 代码

```cpp
class Solution {
public:
    int mm=0;
    int temp=0;
    void findmax(vector<vector<int>>& grid,int i,int j)
    {
        grid[i][j]=0;
        temp++;
        if(i>0&&grid[i-1][j]==1) findmax(grid,i-1,j);
        if((i<grid.size()-1)&&grid[i+1][j]==1) findmax(grid,i+1,j);
        if(j>0&&grid[i][j-1]==1) findmax(grid,i,j-1);
        if((j<grid[i].size()-1)&&grid[i][j+1]==1) findmax(grid,i,j+1);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1) findmax(grid,i,j);               
                mm=max(mm,temp);
                temp=0;
            }
        }
        return mm;
    }
};
```