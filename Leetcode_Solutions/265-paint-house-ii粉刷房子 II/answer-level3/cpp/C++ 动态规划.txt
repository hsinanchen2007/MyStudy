思路比较简单，找到上一个房子粉刷的最小值，和第二最小值，更新下一个房子就可以了
```
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty())
            return 0;
        int res = INT_MAX;
        if (costs.size() == 1) {
            for (auto cost : costs[0]) {
                res = (cost < res) ? cost : res;
            }
            return res;
        }
        int R = costs.size();
        int C = costs[0].size();
        int min1, min1_col;
        int min2;
        for (int i = 1; i < R; ++i) {
            min1 = costs[i - 1][0];
            min1_col = 0;
            min2 = INT_MAX;
            for (int j = 1; j < C; ++j) {
                if (costs[i - 1][j] < min1) {
                    min2 = min1;
                    min1 = costs[i - 1][j];
                    min1_col = j;
                } else if (costs[i - 1][j] < min2) {
                    min2 = costs[i - 1][j];
                }
            }
            for (int j = 0; j < C; ++j) {
                if (j == min1_col) {
                    costs[i][j] = costs[i][j] + min2;
                } else {
                    costs[i][j] = costs[i][j] + min1;
                }
                if (i == R - 1 && costs[i][j] < res)
                    res = costs[i][j];
            }
        }
        return res;
    }
};
```
