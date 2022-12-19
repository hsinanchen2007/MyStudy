```c++
const int maxn = 33;
const int dx[5] = {0, 0, 1, -1};
const int dy[5] = {1, -1, 0, 0};

typedef struct Node {
  int x, y, k, s;
  Node(int a, int b, int c, int d) : x(a), y(b), k(c), s(d) {} 
}Node;

class Solution {
public:
  int shortestPathAllKeys(vector<string>& grid) {
    int f[maxn][maxn][1<<8];
    int k = 0;
    memset(f, -1, sizeof f);
    queue<Node> q;
    int x = -1, y = -1;
    int n = grid.size(), m = grid[0].size();
    auto ok = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '@') {
          x = i, y = j;
        }
        if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
          k |= 1 << (grid[i][j] - 'a');
        }
      }
    }
    q.emplace(Node{x, y, 0, 0});
    f[x][y][0] = 0;
    while (!q.empty()) {
      Node t = q.front(); q.pop();
      if (t.k == k) return t.s;
      for (int i = 0; i < 4; i++) {
        int xx = t.x + dx[i];
        int yy = t.y + dy[i];
        if (!ok(xx, yy) || grid[xx][yy] == '#') continue;
        if (grid[xx][yy] >= 'a' && grid[xx][yy] <= 'z') {
          if (f[xx][yy][t.k | (1 << (grid[xx][yy] - 'a'))] != -1) continue;
          f[xx][yy][t.k | (1 << (grid[xx][yy] - 'a'))] = t.s + 1;
          q.emplace(Node{xx, yy, t.k | (1 << (grid[xx][yy] - 'a')), t.s + 1});
        } else if (grid[xx][yy] >= 'A' && grid[xx][yy] <= 'Z') {
          if ((1 << (grid[xx][yy] - 'A')) & t.k) {
            if (f[xx][yy][t.k] != -1) continue;
            f[xx][yy][t.k] = t.s + 1;
            q.emplace(Node{xx, yy, t.k, t.s + 1});
          }
        } else {
          if (f[xx][yy][t.k] != -1) continue;
          f[xx][yy][t.k] = t.s + 1;
          q.emplace(Node{xx, yy, t.k, t.s + 1});
        }
      }
    }
    return -1;
  }
};
```