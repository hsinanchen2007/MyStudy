这是一个带可清除障碍的BFS问题，一共就$m*n*k$种状态，在队列中维护坐标x,y，消除的障碍数k和当前步数step即可。整体时间复杂度为$O(m*n*k)=40^4=2.56*10^6$。


```
class Solution {
public:
    int vis[41][41][1601];  // 标记当前状态(x, y, k)是否被访问
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};  // 四个方向
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        memset(vis, 0, sizeof(vis));
        queue<vector<int>> q;
        q.push({0, 0, 0, 0}); // {x, y, 已消除的障碍数k, 当前步数step}
        vis[0][0][0] = 1;
        while(!q.empty())
        {
            vector<int> now = q.front();
            q.pop();
            if(now[0]==m-1 && now[1]==n-1) return now[3];
            for(int i = 0; i < 4; i++)
            {
                vector<int> t = now;
                int x = t[0]+dx[i], y = t[1]+dy[i];
                if(x<0 || x>=m || y<0 || y>=n) continue;
                if(grid[x][y]==1) t[2]++;
                if(t[2]>k || vis[x][y][t[2]]==1) continue;
                vis[x][y][t[2]] = 1;
                q.push({x, y, t[2], t[3]+1});
            }
        }
        return -1;  // 无法到达
    }
};
```
