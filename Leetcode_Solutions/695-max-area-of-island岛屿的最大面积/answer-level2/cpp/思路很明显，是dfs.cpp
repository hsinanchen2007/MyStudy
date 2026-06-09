### 解题思路
这道题思路很明显是dfs，但是由于刚开始使用leetcode有点不熟悉这个编辑代码的方式，遇到了一点小坑
**dfs函数需要传入grid的引用（因为这里不能使用在本地自己随便写的全局变量）**，否则的话会因为重复计数导致结果错误
### 代码

```cpp
class Solution {
public:

    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        int cnt = 1;
        cnt += dfs(grid, i+1, j);
        cnt += dfs(grid, i-1, j);
        cnt += dfs(grid, i, j+1);
        cnt += dfs(grid, i, j-1);
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxn = 0;
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++)
                if(grid[i][j]==1)
                    maxn = max(maxn, dfs(grid, i, j));
        return maxn;
    }
};
```