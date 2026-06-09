```c++
const int MAXN = 100;
bool marked[MAXN][MAXN];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
class Solution {
public:
    vector<vector<int>> G;
    int n, m;
    int dfs(int x, int y){
        int ret = 1;
        if(G[x][y] == 0) return 0;
        marked[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(marked[nx][ny] == true) continue;
            ret += dfs(nx,ny) ;
        }
        return ret;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        this->n = n; this->m = m;
        memset(marked, false, sizeof(marked));
        this->G = grid;
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};
```