```cpp
// // 1. 动态规划
// class Solution {
// public:
//     int maxValue(vector<vector<int>>& grid) {
//         int m = grid.size();
//         if (m == 0) return 0;
//         int n = grid[0].size();
//         if (n == 0) return 0;

//         vector<vector<int>> memo(m, vector<int>(n, 0));
//         int up = 0, left = 0;
//         for (int i = 0; i < m; i++)  // 逐行扫描 填memo
//             for (int j = 0; j < n; j++) {
                
//                 if (i-1 < 0) up = 0;
//                 else up = memo[i-1][j];
//                 if (j-1 < 0) left = 0;
//                 else left = memo[i][j-1];

//                 memo[i][j] = max(up, left) + grid[i][j];
//             }
//         return memo[m-1][n-1];
//     }
// };


// 2. 优化的动态规划，存储数组由二维降到一维
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        vector<int> memo(n, 0);
        int up = 0, left = 0;
        for (int i = 0; i < m; i++)  // 逐行扫描 填memo
            for (int j = 0; j < n; j++) {
                
                if (i-1 < 0) up = 0;
                else up = memo[j];
                if (j-1 < 0) left = 0;
                else left = memo[j-1];

                memo[j]= max(up, left) + grid[i][j];
            }
        return memo[n-1];
    }
};



```