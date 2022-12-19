### 解题思路
本题建议和847/854同时食用，注意到这三题都是hard，但其实掌握方法后都不算很难。做完这3道题后，发现对于搜索的理解还是过于浅薄了，一直只会做那种最裸的树/图搜索的题目，其实搜索的本质是对状态进行搜索。“解”也可以构成状态空间。
其实细细想来，动态规划的状态转移方程本质上也是类似的思路。当然只是一点直观的感受，没有啥严谨的证明XD.
下面的代码可以称之为模板式的代码了，并且跑的也挺快……样例数据规模太小了。

### 代码

```cpp
// 0ms
struct State {
    int x, y;
    int r;
    State(int x_, int y_, int r_) {
        x = x_;
        y = y_;
        r = r_;
    }
};

class Solution {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    int shortestPath(vector<vector<int>>& g, int k) {
        int m = g.size(), n = g[0].size();
        if(k >= m + n - 3) return m + n - 2;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, 0)));
        queue<State> Q;
        Q.emplace(0, 0, k);
        int step = 0;
        while(!Q.empty()) {
            int s = Q.size();
            while(s--) {
                auto p = Q.front();
                Q.pop();
                int x = p.x, y = p.y;
                int r = p.r;
                if(x == m - 1 && y == n - 1 && r >= 0) return step;
                if(visited[x][y][r] == 1) continue;
                visited[x][y][r] = 1;
                for(int k = 0; k < 4; k++) {
                    if(x + dx[k] >= 0 && x + dx[k] < m && y + dy[k] >= 0 && y + dy[k] < n) {
                        if(g[x + dx[k]][y + dy[k]] == 1 && r >= 1) Q.emplace(x + dx[k], y + dy[k], r - 1);
                        else if(g[x + dx[k]][y + dy[k]] == 0)
                            Q.emplace(x + dx[k], y + dy[k], r);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
```