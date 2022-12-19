我是按照迷宫2和迷宫3来写的，迷宫2只需在结构体中加上steps并在循环中的while中加上一些操作即可，迷宫3也是稍加修改即可（比如说在结构体中加上string表示目前为止的过程，每次回溯也不会丢失以前的过程），另外关注最后注释掉的恢复visited为未访问，如果不注释掉，能出结果，但是会超时

我研究了一下才反应过来，

原来是因为，如果从某个点无法到达终点，那么这个点就可以设为已访问，以后不要去这个点了，因为这个点肯定无法到终点。

另外比如说从上到达的点的下方向可以设为已访问，以此类推，更节省时间。

bitset<4>就是四个方向，我是想象成上下左右，我觉得这边用int表方向也可以，想象成二进制0000和1111，进行位运算即可，分别与1，2，4，8即可知道是否去过了。


```
class Solution {
 public:
  struct Status {
    int r, c;     // 下标
    bitset<4> d;  // 方向，上下左右
    Status(int rr, int cc, bitset<4> dd) : r(rr), c(cc), d(dd) {}
    Status() {}
    Status(int rr, int cc, string dd) : r(rr), c(cc) { bitset<4> d{dd}; }
  };
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    int n = maze.size(), m = maze[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    stack<Status> tmp;
    bitset<4> d;
    int r, c, tmpr, tmpc;
    Status t;
    tmp.push(Status(start[0], start[1], d));
    while (!tmp.empty()) {
      t = tmp.top();
      tmp.pop();
      r = t.r;
      c = t.c;
      visited[r][c] = 1;
      d = t.d;
      if (r == destination[0] && c == destination[1]) return 1;
      if (!d[0]) {
        d[0] = 1;
        tmpr = r;
        tmpc = c;
        while (tmpr > 0 && !maze[tmpr - 1][tmpc]) --tmpr;
        if (tmpr != r && !visited[tmpr][tmpc]) {
          tmp.push(Status(r, c, d));
          tmp.push(Status(tmpr, tmpc, "1100"));
          continue;
        }
      }
      if (!d[1]) {
        d[1] = 1;
        tmpr = r;
        tmpc = c;
        while (tmpr < n - 1 && !maze[tmpr + 1][tmpc]) ++tmpr;
        if (tmpr != r && !visited[tmpr][tmpc]) {
          tmp.push(Status(r, c, d));
          tmp.push(Status(tmpr, tmpc, "1100"));
          continue;
        }
      }
      if (!d[2]) {
        d[2] = 1;
        tmpr = r;
        tmpc = c;
        while (tmpc > 0 && !maze[tmpr][tmpc - 1]) --tmpc;
        if (tmpc != c && !visited[tmpr][tmpc]) {
          tmp.push(Status(r, c, d));
          tmp.push(Status(tmpr, tmpc, "0011"));
          continue;
        }
      }
      if (!d[3]) {
        d[3] = 1;
        tmpr = r;
        tmpc = c;
        while (tmpc < m - 1 && !maze[tmpr][tmpc + 1]) ++tmpc;
        if (tmpc != c && !visited[tmpr][tmpc]) {
          tmp.push(Status(r, c, d));
          tmp.push(Status(tmpr, tmpc, "0011"));
          continue;
        }
      }
      // visited[r][c] = 0;
    }
    return 0;
  }
};


```