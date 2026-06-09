另一位大佬是按照人BFS，每次判断箱子是否在人的一侧再合法的推动。菜鸡的做法是从箱子的移动出发，判断人是否能到推动箱子的位置。

- 按箱子的位置 BFS，所以状态要包含箱子的位置和当前步数。
- 另一方面，还需要判断玩家能否到箱子移动方向的另一侧，所以还需要在状态中保存玩家位置。
- 综上，BFS 箱子位置，BFS 判每次移动箱子玩家位置是否可到达，BFS套BFS即可

```
class Solution {
public:
  const int maxn = 21,maxm = 21;
  const int dirDelta[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
  
  int n,m;
  
  int minPushBox(vector<vector<char>>& grid) {
    n = grid.size(),m = grid[0].size();
    pos start;
    for(int i = 0;i < n;++i) for(int j = 0;j < m;++j){
      if(grid[i][j] == '.' || grid[i][j] == '#') continue;
      else if(grid[i][j] == 'B') start.bx = i,start.by = j;
      else if(grid[i][j] == 'S') start.px = i,start.py = j;
    }
    
    bool vis[maxn][maxm][maxn][maxm];
    memset(vis,false,sizeof(vis));
    start.s = 0;
    vis[start.bx][start.by][start.px][start.py] = true;
    queue<pos>que;
    que.push(start);
    pos nxt;
    while(!que.empty()){
      const pos cur = que.front();que.pop();
      if(grid[cur.bx][cur.by] == 'T') return cur.s;
      for(int i = 0;i < 4;++i){
        nxt.bx = cur.bx + dirDelta[i][0];
        nxt.by = cur.by + dirDelta[i][1];
        nxt.px = cur.bx - dirDelta[i][0];
        nxt.py = cur.by - dirDelta[i][1];
        
        if(outOfBound(nxt.px,nxt.py,grid))
          continue;
        if(outOfBound(nxt.bx,nxt.by,grid) || vis[nxt.bx][nxt.by][nxt.px][nxt.py])
          continue;
        if(chk(grid,cur.px,cur.py,nxt.px,nxt.py,cur.bx,cur.by)){
          nxt.s = cur.s + 1;
          vis[nxt.bx][nxt.by][nxt.px][nxt.py] = true;
          que.push(nxt);
        }
      }
    }
    return -1;
  }
  /** 
    * 玩家当前的位置 (cpx,cpy) 到需要推箱子的一侧的位置 (npx,npy)
    * 箱子当前位置 (cbx,cby),这里视作障碍，不可越过
  */
  bool chk(vector<vector<char>> grid,int cpx,int cpy,int npx,int npy,int cbx,int cby){
    bool vis[maxn][maxm];
    memset(vis,false,sizeof(vis));
    queue<pos>que;
    pos cur,nex;
    cur.px = cpx,cur.py = cpy;
    vis[cpx][cpy] = true;
    que.push(cur);
    while(!que.empty()){
      cur = que.front();que.pop();
      if(cur.px == npx && cur.py == npy) return true;
      for(int  i = 0;i < 4;++i){
        nex.px = cur.px + dirDelta[i][0];
        nex.py = cur.py + dirDelta[i][1];
        
        if(outOfBound(nex.px,nex.py,grid) || (nex.px == cbx && nex.py == cby) || vis[nex.px][nex.py])
          continue;
        vis[nex.px][nex.py] = true;
        que.push(nex);
      }
    }
    return false;
  }
  
  bool outOfBound(int x,int y,vector<vector<char> >grid){
    return x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#';
  }
  
  class pos{
  public :
    int bx,by,px,py,s;
  };
};
```
