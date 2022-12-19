```
struct coor
    {
        int x,y;
        coor(int num1, int num2){x = num1,y = num2;}
    };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        queue<coor> que;
        que.push(coor(0,0));
        int r = grid.size(), c = grid[0].size();
        int vis[r][c];
        memset(vis, 0, sizeof(vis));
        int dx[] = {0, 0, 1, -1, -1, 1, 1, -1}, dy[] = {1, -1, 0, 0, -1, -1, 1, 1};
        int ans = 1;
        vis[0][0] = 1;
        bool flag = false;
        while(!que.empty())
        {
            int cnt = que.size();
            while(cnt--)
            {
                coor xy = que.front(); que.pop();
                if(xy.x == r - 1 && xy.y == c - 1) 
                {
                    return ans;
                }
                for(int i = 0; i < 8; i++)
                {
                    int x = xy.x + dx[i], y = xy.y + dy[i];
                    if(x < 0 || x >= r || y < 0 || y >= c || grid[x][y] || vis[x][y]) continue;
                    que.push(coor(x,y));
                    vis[x][y] = 1;
                }
            }
            ans++;
        }
        return -1;
    }
```
