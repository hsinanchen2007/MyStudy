## 解题思路一
dfs时，制作通过路径矩阵path, 每通过(x, y)则path[x][y]=1；

```
执行用时 :16 ms, 在所有 C++ 提交中击败了81.43%的用户
内存消耗 :24.4 MB, 在所有 C++ 提交中击败了5.71%的用户
```
### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int c = grid.size();
        if(c==0) return 0;
        int r = grid[0].size();
        vector<vector<int>> path(c, vector<int>(r, 0));
        int res=0;
        for(int i=0; i<c; i++){
            for(int j=0; j<r; j++){
                if(grid[i][j]==1 && path[i][j]!=1)
                    res = max(res, dfs(grid, path, i, j));
            }
        }
        
        return res;
    }
    
private:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& path, int x, int y){
        int c = grid.size();
        int r = grid[0].size();
        if(x<0 || x>=c || y<0 || y >= r || path[x][y]==1 || grid[x][y]==0) return 0;
        path[x][y] = 1;
        return 1 + dfs(grid, path, x+1, y) + dfs(grid, path, x-1, y) + dfs(grid, path, x, y+1) + dfs(grid, path, x, y-1);
    }
};
```

## 解题思路二
dfs时，直接将grid[x][y]=0
省去了path矩阵

```
执行用时 :12 ms, 在所有 C++ 提交中击败了95.81%的用户
内存消耗 :24 MB, 在所有 C++ 提交中击败了5.71%的用户
```

### 代码
```
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int c = grid.size();
        if(c==0) return 0;
        int r = grid[0].size();
        int res=0;
        for(int i=0; i<c; i++){
            for(int j=0; j<r; j++){
                if(grid[i][j]==1)
                    res = max(res, dfs(grid, i, j));
            }
        }
        
        return res;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int x, int y){
        int c = grid.size();
        int r = grid[0].size();
        if(x<0 || x>=c || y<0 || y >= r || grid[x][y]==0) return 0;
        grid[x][y] = 0;
        return 1 + dfs(grid, x+1, y) + dfs(grid, x-1, y) + dfs(grid, x, y+1) + dfs(grid, x, y-1);
    }
};
```

但是为什么内存消耗没有明显降低呢？请问是不是leetcode的BUG???