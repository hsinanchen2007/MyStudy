应该比较简单，注意到移动只有两个方向，那么方向转移的时候很显然。

在描述位置的之后，讨论 (x, y, mask) 三元组即可，这里我们讨论蛇尾的位置，那么蛇头的位置由 mask 唯一确定，就不用记录多余的状态了。

搜索过程应该就是基础 BFS，没什么复杂的。

```cpp
#include <bits/stdc++.h>

using namespace std;

class Solution {
  // Mask
  // 0 -> down
  // 1 -> right
  struct Node {
    int x, y, mask;
    int step;

    Node() : x(0), y(0), mask(0), step(0) {}
  };

  static const int SIZE = 110;
  const int dir[2][2]{{1, 0}, {0, 1}};

  bool vis[SIZE][SIZE][2];

 public:
  Solution() { memset(vis, false, sizeof vis); }

  int minimumMoves(vector<vector<int>>& grid) {
    int N = grid.size();

    // Check if the node itself is a valid state
    auto check = [&](Node n) -> bool {
      if (n.x >= N || n.x < 0 || n.y >= N || n.y < 0) {
        return false;
      }

      if (vis[n.x][n.y][n.mask]) {
        return false;
      }

      if (n.mask == 0) {
        if (n.x + 1 >= N || n.x + 1 < 0) {
          return false;
        }

        return grid[n.x][n.y] != 1 && grid[n.x + 1][n.y] != 1;
      } else if (n.mask == 1) {
        if (n.y + 1 >= N || n.y + 1 < 0) {
          return false;
        }

        return grid[n.x][n.y] != 1 && grid[n.x][n.y + 1] != 1;
      }

      return false;
    };

    // Do rotate, check the point (x+1, y+1) in advance
    // Then just do rotate
    auto rotate_and_check = [&](Node& t) -> bool {
      if (t.x + 1 >= N || t.x + 1 < 0 || t.y + 1 >= N || t.y + 1 < 0) {
        return false;
      }

      if (grid[t.x + 1][t.y + 1] == 1) {
        return false;
      }

      t.mask = !t.mask;

      return check(t);
    };

    vis[0][0][1] = true;
    Node s;
    s.mask = 1;

    queue<Node> que;
    que.push(s);

    while (!que.empty()) {
      Node n = que.front();
      que.pop();

      if (n.x == N - 1 && n.y == N - 2 && n.mask == 1) {
        return n.step;
      }

      for (int i = 0; i < 2; i++) {
        Node t = n;
        t.x += dir[i][0];
        t.y += dir[i][1];

        if (check(t)) {
          t.step++;
          vis[t.x][t.y][t.mask] = true;
          que.push(t);
        }
      }

      Node t = n;
      if (rotate_and_check(t)) {
        t.step++;
        vis[t.x][t.y][t.mask] = true;
        que.push(t);
      }
    }

    return -1;
  }
};
```
