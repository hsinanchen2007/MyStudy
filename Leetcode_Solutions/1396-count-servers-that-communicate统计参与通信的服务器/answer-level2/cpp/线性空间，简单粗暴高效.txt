只需要同行或者同列服务器数目大于1，那么当前位置的服务器一定拥有联通的机器

```c++
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rows(grid.size()), cols(grid[0].size());
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) ++res;
            }
        }
        return res;
    }
};
```

