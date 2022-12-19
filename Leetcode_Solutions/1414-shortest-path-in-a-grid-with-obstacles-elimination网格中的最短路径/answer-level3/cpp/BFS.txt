n 和 m 都挺小的， 所以总共的需要消除的障碍就 n*m 个。到达同一个格子时消除过的障碍数不同视作不同。总共 (n*m)^2 个，用 bool 标记，记忆化即可。

同一个障碍消除多次重复计数了的(没有在记录修改后的图)

```
class Solution {
 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    queue<node>que;
    const int inf = 0x3f3f3f3f;
    int ans = inf;
    n = grid.size(), m = grid[0].size();
    que.push(node(0, 0, k, 0));

    while(!que.empty()) {
      node cur = que.front();
      que.pop();
      if(grid[cur.r][cur.c])
        cur.k--;
      vis[cur.r][cur.c][k-cur.k] = true;

      if(cur.r == n - 1 && cur.c == m - 1 && cur.k >= 0) {
        ans = min(ans, cur.s);
      }
      for(int  i = 0, rr, cc; i < 4; ++i) {
        rr = cur.r + dr[i], cc = cur.c + dc[i];
        if(inBound(rr, cc) && !vis[rr][cc][k-cur.k] && k-cur.k <= n*m) {
          que.push(node(rr, cc, cur.k, cur.s + 1));
          vis[rr][cc][k-cur.k] = true;
        }
      }
    }
    return ans == inf ? -1: ans;
  }

 private :
  struct node {
    int r, c, k, s;

    node(int _r,int _c,int _k,int  _s):r(_r),c(_c),k(_k),s(_s){};
  };

  inline bool inBound(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
  }
  const int dr[4] = {1, -1, 0, 0};
  const int dc[4] = {0, 0, 1, -1};
  int n,m;
  bool vis[41][41][41*41];
};

```