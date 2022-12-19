![1584177526(1).png](https://pic.leetcode-cn.com/c163d69c931261a3e433d27c4fe02168d5bce8013b63cd8381bbf28a5eb7fe6d-1584177526\(1\).png)


```
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int mg = 0;
        for(int n = 0; n < grid.size(); n ++)
        {
            for(int m = 0; m < grid[n].size(); m++)
            {
                if(grid[n][m] != 0) mg = max(mg,backtract(0,grid,n,m));
            }
        }
        return mg;
    }
    int backtract(int mg, vector<vector<int>> &grid, int n, int m)
    {
        mg += grid[n][m];
        int p = grid[n][m];
        grid[n][m] = 0;
        int k = mg;
        if(n>0&&grid[n-1][m]!= 0) k = max(k,backtract(mg,grid,n-1,m));
        if(n < grid.size()-1&&grid[n+1][m] !=0) k =max(k,backtract(mg,grid,n+1,m));
        if(m >0&&grid[n][m-1] != 0) k = max(k,backtract(mg,grid,n,m-1));
        if(m < grid[n].size()-1&&grid[n][m+1] != 0) k = max(k,backtract(mg,grid,n,m+1));
        grid[n][m] = p;
        return k;    
    }
};
```

