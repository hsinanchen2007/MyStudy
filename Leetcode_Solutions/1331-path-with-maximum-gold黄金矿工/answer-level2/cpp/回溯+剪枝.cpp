### 解题思路
见注释
执行用时24ms，内存消耗7.2MB

### 代码

```cpp
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        //这道题可以剪枝，选择好的起始点
        //如果不剪枝也可以通过
        int m = grid.size();
        int n = grid[0].size();
        int sum_gold = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int flag = 1;
                if(i - 1 < m && j < n && i - 1 >= 0 && j >= 0) {
                    if(grid[i - 1][j] == 0) flag = 0;
                }
                if(i + 1 < m && j < n && i + 1 >= 0 && j >= 0) {
                    if(grid[i + 1][j] == 0) flag = 0;
                }
                if(i < m && j + 1 < n && i >= 0 && j + 1 >= 0) {
                    if(grid[i][j + 1] == 0) flag = 0;
                }
                if(i < m && j - 1 < n && i >= 0 && j - 1 >= 0) {
                    if(grid[i][j - 1] == 0) flag = 0;
                }
                //经过分析，起点必须旁边有0，且不能是0
                if(flag == 0 && grid[i][j] != 0) sum_gold = max(sum_gold, dfs(grid, i, j, m, n));
                else continue;
            }
        }
        //需要考虑金矿中没有0的情况
        if(sum_gold == 0) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    sum_gold += grid[i][j];
                }
            }
        }
        return sum_gold;
    }
    int dfs(vector<vector<int>> &grid, int a, int b, int len, int hei) {
        //超出金矿范围，已经挖过矿，或者原本没有矿，直接返回0
        //如果是“grid”而不是“&grid”，会超时
        if(a >= len || b >= hei || a < 0 || b < 0 || grid[a][b] == 0) return 0;
        int max_gold = 0;
        int temp = grid[a][b];
        grid[a][b] = 0;
        max_gold = max(dfs(grid, a + 1, b, len, hei), dfs(grid, a, b + 1, len, hei));
        max_gold = max(max_gold, dfs(grid, a - 1, b, len, hei));
        max_gold = max(max_gold, dfs(grid, a, b - 1, len, hei));
        max_gold += temp;
        grid[a][b] = temp;
        return max_gold;
    }
};
```