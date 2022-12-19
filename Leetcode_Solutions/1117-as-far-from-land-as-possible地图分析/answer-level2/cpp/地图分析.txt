### 解题思路
可以看一下[官方题解](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/di-tu-fen-xi-by-leetcode-solution/)拓展一下思路。

### 朴素BFS代码

- 思路：每个海洋的点都考虑一遍，每个点都做一次BFS找出离它距离最近的陆地的距离，然后把每个海洋的点遍历完取最大值，就是答案！
- 时间复杂度：每个点做BFS最差是O(N^2)，最差情况是每个点都要跑一遍BFS（全是海洋的情况）,所以时间复杂度为O(N^4)，N不超过100，所以不会超时！

```cpp
typedef pair<int,int> PII;
bool st[110][110];
int dist[110][110];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int len;

class Solution {
public:
    int bfs(int x,int y,vector<vector<int>>& grid)
    {
        queue<PII> q;
        q.push({x,y});
        st[x][y] = true;
        dist[x][y] = 0;
        
        while(q.size())
        {
            PII t = q.front();
            st[t.first][t.second] = false;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int xx = t.first + dx[i], yy = t.second + dy[i];
                if(xx<0 || xx>=len || yy<0 || yy>=len || dist[xx][yy] != -1) continue;
                dist[xx][yy] = dist[t.first][t.second] + 1;
                if(grid[xx][yy] == 1) return dist[xx][yy];
                if(!st[xx][yy])
                {
                    st[xx][yy] = true;
                    q.push({xx,yy});
                }
            }
        }
        return -1;
    }

    int maxDistance(vector<vector<int>>& grid) {
        len = grid.size();
        int maxv = -1;
        for(int i = 0;i<len;i++)
        {
            for(int j = 0;j<len;j++)
            {
                if(grid[i][j] == 0)
                {
                    memset(dist,-1,sizeof(dist));
                    memset(st,false,sizeof st);
                    maxv = max(maxv,bfs(i,j,grid));
                }
            }
        }
        return maxv;
    }
};
```

### 多源BFS代码

思路和下面两篇题解相同,可以看一看，比较直观
[dalao1](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/lu-di-bu-duan-chang-da-zhi-dao-fu-gai-zheng-ge-di-/)
[dalao2](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/zhen-liang-yan-sou-huan-neng-duo-yuan-kan-wan-miao/)
- 思路：将每个陆地的点都入队，同时开始让这些陆地开始长大，直到整个地图被陆地覆盖，此时最大的dist就是答案
- 时间复杂度，每个点只被遍历一遍，所以时间复杂度为 O(N^2)

```cpp
typedef pair<int,int> PII;
bool st[110][110];
int dist[110][110];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int len,maxv;

class Solution {
public:
    void bfs(vector<vector<int>>& grid)
    {
        len = grid.size();
        maxv = -1;
        queue<PII> q;
        memset(st,false,sizeof st);
        memset(dist,-1,sizeof dist);
        for(int i = 0; i<len ;i++)
            for(int j = 0; j<len ;j++)
            {
                if(grid[i][j] == 1)     //将每个陆地都入队
                {
                    q.push({i,j});
                    st[i][j] = true;
                    dist[i][j] = 0;
                }
            }
        
        while(q.size())
        {
            PII t = q.front();
            st[t.first][t.second] = false;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int xx = t.first + dx[i], yy = t.second + dy[i];
                if(xx<0 || xx>=len || yy<0 || yy>=len || dist[xx][yy] != -1) continue;
                dist[xx][yy] = dist[t.first][t.second] + 1;
                if(!st[xx][yy])
                {
                    st[xx][yy] = true;
                    q.push({xx,yy});
                }
            }
        }
        //找出最大距离
        for(int i = 0; i<len ;i++)
            for(int j = 0; j < len;j++)
                maxv = max(maxv,dist[i][j]);
        if(maxv == 0) maxv = -1;    //maxv=0说明整张图全是1，maxv没有被更新，整张图全是0时，不会有点进队，所以maxv为-1
    }

    int maxDistance(vector<vector<int>>& grid) {
        bfs(grid);
        return maxv;
    }
};
```