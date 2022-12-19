使用BFS宽度优先遍历，并用三维数组存储该状态（x、y、剩余可消除数）是否已经到达过。
```cpp
class Solution {
private:
    struct node {
        int x, y;
        int t;
        int hp;
        node(int a, int b, int c, int _t) : x(a), y(b), hp(c), t(_t) {}
    };
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        bool vis[m][n][k + 1] = {};
        queue <node> q;
        vis[0][0][k] = 1;
        q.push(node(0, 0, k, 0));
        while(!q.empty()) {
            node u = q.front();
            q.pop();
            if (u.x == m - 1 && u.y == n - 1) {
                return u.t;
            }
            for (int i = 0; i < 4; i++) {
                int tx = u.x + dx[i], ty = u.y + dy[i];
                if (tx >= 0 && tx < m && ty >= 0 && ty < n) {
                    if (!vis[tx][ty][u.hp]) {
                        if (grid[tx][ty] != 1) {
                            q.push(node(tx, ty, u.hp, u.t + 1));
                            vis[tx][ty][u.hp] = 1;
                        }
                        else if (grid[tx][ty] == 1 && u.hp > 0) {
                            q.push(node(tx, ty, u.hp - 1, u.t + 1));
                            vis[tx][ty][u.hp] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
```
