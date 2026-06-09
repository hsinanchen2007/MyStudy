## BFS

使用队列保存为1块的上下左右邻居。

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0){
            return 0;
        }
        int lists = grid[0].size();

        int res = 0;
        int tmp = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<lists;j++){
                if(grid[i][j]==1){
                    tmp = 0;
                    grid[i][j]=0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        tmp++;
                        auto cur = q.front();
                        q.pop();
                        int x = cur.first;
                        int y = cur.second;
                        if(x>=1 && grid[x-1][y]==1){
                            q.push({x-1,y});
                            grid[x-1][y]=0;
                        }
                        if(x<rows-1 && grid[x+1][y]==1){
                            q.push({x+1,y});
                            grid[x+1][y]=0;
                        }
                        if(y>=1 && grid[x][y-1]==1){
                            q.push({x,y-1});
                            grid[x][y-1]=0;
                        }
                        if(y<lists-1 && grid[x][y+1]==1){
                            q.push({x,y+1});
                            grid[x][y+1]=0;
                        }
                    }
                }
                res = max(res,tmp);
            }
        }
        return res;
    }
};
```

## DFS

遇到为1的块，递归其上下左右邻居
```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    ans = max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& grid,int i,int j){
        int rows = grid.size();
        int lists = grid[0].size();

        grid[i][j] = 0;
        int ans = 1;
        if(i>=1 && grid[i-1][j]==1){
            ans += dfs(grid,i-1,j);
        }
        if(i<rows-1 && grid[i+1][j]==1){
            ans += dfs(grid,i+1,j);
        }
        if(j>=1 && grid[i][j-1]==1){
            ans += dfs(grid,i,j-1);
        }
        if(j<lists-1 && grid[i][j+1]==1){
            ans += dfs(grid,i,j+1);
        }
        return ans;
    }
};
```