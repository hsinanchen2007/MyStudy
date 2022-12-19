这道题一看就是BFS问题，问题在于怎么使用BFS。本菜鸡一开始误入歧途，后面改邪归正，不知道有没有同道中人。

另外本菜鸡在一直刷题，欢迎关注我的公众号[热爱生活的小熊猫]哦~


## 1 笨方法

[这个是我自己想的笨方法， 可以直接看下面的解法2😂]

一开始我想直接从每个海域的位置出发做bfs，找到每个海域到最近的陆地的最近距离后，再选择这些距离里面的最远的距离即可（就是一个最暴力的解法），但会超时或爆内存。

无法通过的bfs代码：

```c++
class Solution {
public:
    struct Position{
        int row, col, depth;
        Position() {}
        Position(int r, int c, int d) : row(r), col(c), depth(d) {}
    };
    int bfs(vector<vector<int>>& grid, int row, int col) {
        int n = grid.size();
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[row][col] = 1;
        queue<Position> que;
        que.push(Position(row, col, 0));
        while (!que.empty()) {
            Position cur = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int r_ = cur.row + dirs[i][0];
                int c_ = cur.col + dirs[i][1];
                if (r_ >= 0 && r_ < n && c_ >= 0 && c_ < n && visited[r_][c_] == 0) {
                    if (grid[r_][c_] == 1) {
                        return cur.depth + 1;
                    }
                    visited[r_][c_] = 1;
                    que.push(Position(r_, c_, cur.depth + 1));
                }
            }
        }
        return -1;
    }

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int seas = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) seas++;
            }
        }
        if (seas == 0 || seas == n * n) return -1;

        int ret = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    ret = max(ret, bfs(grid, i, j));
                }
            }
        }
        return ret;
    }
};
```



## 2 好方法

上面的暴力解法无法AC，因为它太复杂了，最坏的情况下每次寻找小岛都要驶过大半锅海洋，因此需要寻找一个更好的解法。在经过一番冥思苦想之后，我从大佬们那里学到了新的思路[1]。我也不知道自己是怎么想到前面的辣鸡解法的，正常的思路不应该是从每个小岛出发吗？遍历的流程就应该如下图所示，最后到达的海域的距离即为所求：

![1162-1.png](https://pic.leetcode-cn.com/a4ab89da9c742080b792d19e1b30fc0aeb569313fbc50843c0a43e9bb6c581c8-1162-1.png)


因此只需要在一开始的时候将所有小岛都加入队列中，进行BFS遍历，队列中最后的那个位置的距离即为所求。

弱鸡的可以通过的代码：

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> que;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    que.push(make_pair(i, j));
                }
            }
        }
        if (que.empty() || que.size() == n * n) return -1;

        pair<int, int> cur;
        while (!que.empty()) {
            cur = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int r_ = cur.first + dirs[i][0];
                int c_ = cur.second + dirs[i][1];
                if (r_ >= 0 && r_ < n && c_ >= 0 && c_ < n && grid[r_][c_] == 0) {
                    grid[r_][c_] = grid[cur.first][cur.second] + 1;
                    que.push(make_pair(r_, c_));
                }
            }
        }
        return grid[cur.first][cur.second] - 1;
    }
};
```

![image.png](https://pic.leetcode-cn.com/bb7f04463c2fc097c2092360c10ec5cd6d409a5c8252e8c1c0902f0a4817cc5f-image.png)