![屏幕快照 2019-10-05 上午11.19.22.png](https://pic.leetcode-cn.com/dc0cfca8d5cc4f38db4e6328e7dd802a5d090decc062fcb30e1efdecfb518fe6-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-10-05%20%E4%B8%8A%E5%8D%8811.19.22.png)

``` C++
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int m = grid.size(), n = grid[0].size();
        // bfs
        queue<vector<int>> q;
        q.push({r0, c0});
        vector<vector<int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        auto res = grid;
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            vis[v[0]][v[1]] = true;
            int cnt = 0; // 记录四个方向上颜色相同正方形的个数
            for(auto& d: direct) {
                int x = v[0]+d[0], y = v[1]+d[1];
                if(x<0||x>=m||y<0||y>=n) continue;
                if(grid[x][y]!=grid[r0][c0]) continue;
                cnt++;
                if(vis[x][y]) continue;
                q.push({x, y});
            }
            // 小于4个表示当前位置为边界
            if(cnt<4) res[v[0]][v[1]] = color;
        }
        return res;
    }
};
```
