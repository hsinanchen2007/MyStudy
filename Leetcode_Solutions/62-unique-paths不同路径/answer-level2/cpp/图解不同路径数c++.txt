### 解题思路
![62.mp4](e8fef310-82ca-4b0d-a2ba-a64fe9045e86)


### 代码

```cpp
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         for(int i = 0; i < m; ++i){
//             for(int j = 0; j < n; ++j){
//                 dp[i][i] = (i > 0 && j >0 ) ? dp[i][j] = dp[i][j-1] + dp[i-1][j] : 1;
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };
//优化
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                dp[j] = (i > 0 && j >0 ) ? dp[j] = dp[j-1] + dp[j] : 1;
            }
        }
        return dp[n-1];
    }
};
```