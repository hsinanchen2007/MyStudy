### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        //统计每行，每列各有多少台机器
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int res = 0;
        //遍历网络，若果该点存在计算机，同时改行或者该列存在其他计算机，结果+1；
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) res++;
            }
        }
        return res;
    }
};
```