### 解题思路
寻找岛屿数量。
实际上就是在主函数对那些没有被访问过的岛屿进行二重循环遍历。
遇到是岛屿1的，那么利用dfsdfs把他身边所有的1都标记为已经被访问过。

### 代码

```cpp
class Solution {
public:
    int X[4][2]={0,1,1,0,0,-1,-1,0};
    int numIslands(vector<vector<char>>& grid) {
        // 图的遍历，而不是一颗树
        if(grid.empty()) return 0;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> visit(r,vector<int>(c,0));
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'&&visit[i][j]==0){
                    ans++;
                    dfs(grid,visit,i,j);
                }
            }
        }
        return ans;

    }
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &visit, int x,int y){
             if(x<grid.size()&&x>=0&&y<grid[0].size()&&y>=0){
                 if(grid[x][y]=='1'&&visit[x][y]==0){
                        visit[x][y]=1;
                        for(int i=0;i<4;i++){
                            int next_x = x + X[i][0];
                            int next_y = y + X[i][1];
                            dfs(grid,visit,next_x,next_y);
                        }
                 }
             }
             return;
    }
};
```