
bfs确定最短距离，dfs确定当前点能到的点
```
class Solution {
public:
int dx[4] = {0,0,1,-1} , dy[4] = {1,-1,0,0};
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        pair<int,int> end;
        end.first = n-1,end.second = m-1;
        dfs(0,0,vis,q,grid);
        int step = 0;
        while(q.size()){
            int t = q.size();
            step++;
            while(t--){
                pair<int,int> p = q.front();
                q.pop();
                if(p == end) return step-1;
                int x = p.first , y = p.second;
                for(int i = 0;i < 4;i++){
                    int xx = x+dx[i] , yy = y+dy[i];
                    if(xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy]){
                        dfs(xx,yy,vis,q,grid);
                    }
                }
            }
        }
        return 0;
    }
    void dfs(int x,int y,vector<vector<int>>& vis,queue<pair<int,int>>& q,vector<vector<int>>& grid){
        if(vis[x][y]) return;
        pair<int,int> tmp;
        tmp.first = x,tmp.second = y;
        q.push(tmp);
        vis[x][y] = 1;
        int t = grid[x][y];
        int xx = x+dx[t-1] , yy = y+dy[t-1];
        if(xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid[0].size()) dfs(xx,yy,vis,q,grid);
        return;
    }
};
```