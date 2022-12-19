## 不同路径I 
### 链接
https://leetcode-cn.com/problems/unique-paths
### 思路
用长度为`m`, 宽度为`n`的二维数组`dp`保存走到`(i, j)`空格的路径数。则`dp[i][j] = dp[i - 1][j] + dp[i][j-1]`.
`dp[m-1][n-1]`则为从`(0, 0)`走到`(m-1, n-1)`的路径数。
### C++代码
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<uint32_t>> dp(m, vector<uint32_t>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - 1 >= 0) dp[i][j] += dp[i-1][j];
                if (j - 1 >= 0) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.uniquePaths(23, 12) << endl;
    cout << solution.uniquePaths(4, 2) << endl;
    cout << solution.uniquePaths(3, 2) << endl;
    cout << solution.uniquePaths(7, 3) << endl;
    return 0;
}
```

## 不同路径II
### 链接
https://leetcode-cn.com/problems/unique-paths-ii/
### 思路
和上一题目差不多，只是遇到障碍物(`obstacleGrid[i][j] == 1`)的时候路径数为0.
### C++代码
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = (int)obstacleGrid.size(), n = (int)obstacleGrid[0].size();
        vector<vector<uint32_t>> dp(m, vector<uint32_t>(n, 0));
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) continue;
                if (i) dp[i][j] += dp[i-1][j];
                if (j) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
```