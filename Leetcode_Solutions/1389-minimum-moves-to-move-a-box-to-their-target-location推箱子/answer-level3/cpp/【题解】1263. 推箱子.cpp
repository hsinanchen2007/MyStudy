**方法一：广度优先搜索**

对于二维矩阵中求最短路的问题，我们一般可以使用广度优先搜索 + 队列的方法解决。在本题中，如果没有玩家，而是箱子每一步可以自行向四个方向移动一格，那么我们就可以从箱子的初始位置开始，使用二元组 `(x, y)`，即箱子的坐标表示状态，通过广度优先搜索，直至搜索到目标位置。然而本题需要玩家推动箱子，因此只用二元组 `(x, y)` 表示一个状态是不够的，因为玩家的可移动范围是随着箱子位置的变化而变化的。因此我们可以考虑用四元组 `(bx, by, mx, my)` 表示一个状态，其中 `(bx, by)` 表示箱子的位置，`(mx, my)` 表示玩家的位置。

对于当前的状态 `(bx, by, mx, my)`，它可以向最多四个新状态进行搜索，即将玩家 `(mx, my)` 向四个方向移动一格。假设移动的方向为 `(dx, dy)`，那么玩家的新位置为 `(mx + dx, my + dy)`。如果该位置为地板且箱子不在此处，那么根据题目要求，玩家移动到新位置不计入推动次数。如果该位置为箱子 `(bx, by)`，那么箱子可能的新位置为 `(bx + dx, bx + dy)`，如果该位置为地板，那么箱子会被推动，根据题目要求，计入一次推动次数。当箱子到达了目标位置，我们就得到了最小推动次数。

注意到上面的方法存在一个小问题，假设状态 `S` 可以向两个状态 `S1` 和 `S2` 进行搜索，`S1` 中箱子被推动，`S2` 中箱子未被推动。由于 `S1` 相较于 `S2` 先进入队列，因此我们并没有按照广度优先搜索的要求，先搜索小状态，后搜索大状态。因此当我们有搜索队列 `q` 时，对于 `q` 中的每一个状态 `S` 可以得到的新状态 `Sx`，如果 `Sx` 中箱子未被推动，那么可以直接将 `Sx` 加入队列末尾；如果 `Sx` 中箱子被推动，那么需要将 `Sx` 加入一个新的队列 `nq` 中。可以发现，`q` 中所有的状态都有着相同的推动次数 `k`，而 `nq` 中所有的状态都有着相同的推动次数 `k + 1`。在 `q` 中所有状态都搜索完毕，即 `q` 为空时，我们将 `nq` 赋予 `q`，再开始新的一轮广度优先搜索。这样我们就保证了先搜索小状态，后搜索大状态的策略。

```C++ [sol1]
struct Dwell {
    int box_x, box_y;
    int man_x, man_y;
    Dwell(int _bx, int _by, int _mx, int _my): box_x(_bx), box_y(_by), man_x(_mx), man_y(_my) {}
};

class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dist[m][n][m][n];
        memset(dist, -1, sizeof(dist));
        
        int box_x, box_y;
        int start_x, start_y;
        int end_x, end_y;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'B') {
                    box_x = i;
                    box_y = j;
                    grid[i][j] = '.';
                }
                else if (grid[i][j] == 'S') {
                    start_x = i;
                    start_y = j;
                    grid[i][j] = '.';
                }
                else if (grid[i][j] == 'T') {
                    end_x = i;
                    end_y = j;
                    grid[i][j] = '.';
                }
            }
        }

        queue<Dwell> q;
        q.emplace(box_x, box_y, start_x, start_y);
        dist[box_x][box_y][start_x][start_y] = 0;

        while (!q.empty()) {
            queue<Dwell> nq;
            while (!q.empty()) {
                Dwell cur = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int nxt_x = cur.man_x + dirs[i][0];
                    int nxt_y = cur.man_y + dirs[i][1];
                    if (nxt_x >= 0 && nxt_x < m && nxt_y >= 0 && nxt_y < n) {
                        if (cur.box_x == nxt_x && cur.box_y == nxt_y) {
                            int nxt_box_x = cur.box_x + dirs[i][0];
                            int nxt_box_y = cur.box_y + dirs[i][1];
                            if (nxt_box_x >= 0 && nxt_box_x < m && nxt_box_y >= 0 && nxt_box_y < n) {
                                if (grid[nxt_box_x][nxt_box_y] == '.' && dist[nxt_box_x][nxt_box_y][nxt_x][nxt_y] == -1) {
                                    nq.emplace(nxt_box_x, nxt_box_y, nxt_x, nxt_y);
                                    dist[nxt_box_x][nxt_box_y][nxt_x][nxt_y] = dist[cur.box_x][cur.box_y][cur.man_x][cur.man_y] + 1;
                                    if (nxt_box_x == end_x && nxt_box_y == end_y) {
                                        return dist[nxt_box_x][nxt_box_y][nxt_x][nxt_y];
                                    }
                                }
                            }
                        }
                        else {
                            if (grid[nxt_x][nxt_y] == '.' && dist[cur.box_x][cur.box_y][nxt_x][nxt_y] == -1) {
                                q.emplace(cur.box_x, cur.box_y, nxt_x, nxt_y);
                                dist[cur.box_x][cur.box_y][nxt_x][nxt_y] = dist[cur.box_x][cur.box_y][cur.man_x][cur.man_y];
                            }
                        }
                    }
                }
            }
            q = nq;
        }
        

        return -1;
    }
};
```

**复杂度分析**

- 时间复杂度：$O(M^2N^2)$。

- 空间复杂度：$O(M^2N^2)$。