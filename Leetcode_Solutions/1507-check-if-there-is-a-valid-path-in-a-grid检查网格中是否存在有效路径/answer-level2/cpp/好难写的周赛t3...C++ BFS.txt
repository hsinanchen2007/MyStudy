主要思想是：用数组 d 存每条路的两个转移方向。然后暴力 BFS 即可。 每次要检查是否出了边界，以及check转移到的下一条路是否合法。
check方法：注意到若合法，则本次往后的转移，和后面数组d的某个方向的转移，数值加起来必须是0. 即 sum[0] == sum[1] == 0

```c++
class Solution {
public:
    vector<vector<vector<int>>> d = {
        {{-100, -100}, {-100, -100}},// placeholder
        {{0, -1}, {0, 1}},  // 1
        {{-1, 0}, {1, 0}},  // 2
        {{0, -1}, {1, 0}},  // 3
        {{1, 0}, {0, 1}}, // 4
        {{0, -1}, {-1, 0}},// 5
        {{-1, 0}, {0, 1}} // 6
        };
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int vis[m + 1][n + 1];
        memset(vis, 0, sizeof vis);
        vector<int> t0(2);
        queue<vector<int>> q;
        q.push(t0);
        
        while (!q.empty())
        {
            auto t0 = q.front(); q.pop();
            vis[t0[0]][t0[1]] = 1;
            if (t0[0] == m - 1 && t0[1] == n - 1) return true;
            int cur = grid[t0[0]][t0[1]];
            vector<int> t1{t0[0] + d[cur][0][0], t0[1] + d[cur][0][1]};
            vector<int> t2{t0[0] + d[cur][1][0], t0[1] + d[cur][1][1]};
            if (t1[0] >= 0 && t1[0] < m && t1[1] >= 0 && t1[1] < n) {
                int nx_1 = grid[t1[0]][t1[1]];
                if (!vis[t1[0]][t1[1]] && check(d[cur][0], d[nx_1])) q.push(t1);
            }
            if (t2[0] >= 0 && t2[0] < m && t2[1] >= 0 && t2[1] < n) {
                int nx_2 = grid[t2[0]][t2[1]];
                if (!vis[t2[0]][t2[1]] && check(d[cur][1], d[nx_2])) {
           //         cout << "cur : " << cur << "   " << "nx2 : " << nx_2 << endl;
                    q.push(t2);
                }
            }
        }
        return false;
    }
    
    bool check(vector<int> cur_dir, vector<vector<int>> nx) {
        for (auto line : nx) {
            vector<int> sum(2);
            for (int i = 0; i < 2; i ++) {              
                 sum[i] = cur_dir[i] + line[i];
            }
            if (sum[0] == 0 && sum[1] == 0) return true;
        }
        return false;
    }
};
```