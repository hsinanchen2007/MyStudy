```
struct XY
    {
        int x,y;
        XY(int m, int n)
        {
            x = m, y = n;
        }
    };
    int r, c;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        r = grid.size(), c = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    bfs(grid, i, j, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<char>>& grid, int cx, int cy, vector<vector<bool>>& vis)
    {
        queue<XY> que;
        que.push(XY(cx,cy));
        vis[cx][cy] = true;
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        while(!que.empty())
        {
            XY xy = que.front(); que.pop();
            for(int i = 0; i < 4; i++)
            {
                int x = dx[i] + xy.x, y = dy[i] + xy.y;
                if(x<0 || x>=r || y<0 || y>=c || vis[x][y] || grid[x][y]=='0') continue;
                que.push(XY(x,y));  
                vis[x][y] = true;
            }
        }
    }
```
