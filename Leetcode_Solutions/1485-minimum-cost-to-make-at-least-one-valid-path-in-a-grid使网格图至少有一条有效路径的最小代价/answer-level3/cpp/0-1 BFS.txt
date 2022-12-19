### 解题思路

单源最小路径，边权值可以是0或者1，时间复杂度 O(E)。
参考了 [@wnjxyk](/u/wnjxyk/) 的[题解](https://leetcode-cn.com/circle/discuss/y0Hu6V/view/Vf82NM/)。

1. 因为同一节点可能多次松弛，所以不需要 Visited记录访问过的节点；
2. 因为最终松弛条件不满足了，所以不会无限次重复访问节点。

### 代码

```cpp
class Solution {
private:
    int dir[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    int m;
    int n;
    vector<vector<int>> dp;
public:
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        
        deque<pair<int, int>> Q;
        Q.emplace_back(0, 0);
        dp[0][0] = 0;
        
        while(!Q.empty()) {
            auto cur = Q.front();
            Q.pop_front();
            int x = cur.first;
            int y = cur.second;

            // 网格指示的方向
            int idx = grid[x][y] - 1;
            for(int i=0; i<4; i++) {
                int weight = (i == idx) ? 0 : 1;
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                // 1。未访问过； 2. 可以松弛.
                if(dp[nx][ny] == -1 || dp[nx][ny] > dp[x][y] + weight) {
                    dp[nx][ny] = dp[x][y] + weight;
                    if(i == idx){
                        Q.emplace_front(nx, ny);
                    } else {
                        Q.emplace_back(nx, ny);
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};
```