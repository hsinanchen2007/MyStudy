
标记为0表示访问过，同时用临时变量保存以便恢复

```
class Solution {
public:
    int max=0;
    void visit(vector<vector<int>>& grid,int preSum,int i,int j)  //i,j is the coordinate that will visit
    {
        max=std::max(preSum,max);
        if(!(i>=0&&i<grid.size()&&j>=0&&j<grid[0].size())||grid[i][j]==0)
        {
            return;
        }
        int tmp=grid[i][j];
        grid[i][j]=0;
        visit(grid,preSum+tmp,i+1,j);
        visit(grid,preSum+tmp,i-1,j);
        visit(grid,preSum+tmp,i,j-1);
        visit(grid,preSum+tmp,i,j+1);
        grid[i][j]=tmp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                visit(grid,0,i,j);
            }
        }
        return max;
    }
};
```
