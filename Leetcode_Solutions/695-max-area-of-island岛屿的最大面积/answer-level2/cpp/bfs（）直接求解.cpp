### 解题思路
bfs（），每次便利找到1的点，就bfs一次，每次记录便利的点的个数，便利过得点用vis标记，最后取出最大的

### 代码

```cpp
typedef pair<int, int> P;

class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0 ,0, -1, 1};
    bool vis[55][55];
    int n, m;
    
    bool ok(int x, int y, vector<vector<int> >& grid){
        //这里需要注意，题目中给的是int型号的地图，不是char型的，所以不能用'0'进行判断
        if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0)return false;
        return true;
    }
    
    int bfs(int x, int y, vector<vector<int>>& grid){
        int ans = 1;
        queue<P> q;
        vis[x][y] = true;
        q.push(P(x, y));
        while(!q.empty()){
            P tem = q.front();
            q.pop();
            for(int i = 0;i < 4;i++){
                int tx = tem.first + dx[i];
                int ty = tem.second + dy[i];
                if(ok(tx,ty,grid) && !vis[tx][ty]){
                    vis[tx][ty] = true;
                    ans++;
                    q.push(P(tx, ty));
                }
            }
        }
        return ans;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(vis, false, sizeof vis);
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    ans = max(ans, bfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};
```