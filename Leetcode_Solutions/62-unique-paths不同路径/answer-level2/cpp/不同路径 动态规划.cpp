### 解题思路
格子 (i, j) 都可以从左边 (i, j-1) 来或者从上面(i-1, j)来
假设到达格子 (i, j-1)有 dp[i][j-1]种方法，到达格子 (i-1, j)有 dp[i-1][j]种方法，
则到达格子 (i, j) 的方法有 dp[i][j] = dp[i][j-1] + dp[i-1][j]
*边缘格子只能有一种到达方式，即从左边或者从上面


### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (0==m || n==0)
            return 1;

        const int x = m;
        const int y = n;

        int** dp = new int*[x];
        
        for (int i=0; i<m; ++i) {
            dp[i] = new int[n];
            for (int j=0; j<n; ++j) {
                if (i==0 && j==0) {
                    dp[0][0] = 1;
                    continue;
                }

                int to_right = i==0 ? 0 : dp[i-1][j];
                int to_down = j==0 ? 0 : dp[i][j-1];
                dp[i][j] = to_down + to_right;
            }
        }
        
        auto ans = dp[m-1][n-1];
        delete[] dp;
        return ans;
    }
};
```