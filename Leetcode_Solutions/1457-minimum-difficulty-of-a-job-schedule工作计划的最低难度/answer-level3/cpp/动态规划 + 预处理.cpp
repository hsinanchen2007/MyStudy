### 解题思路

DP公式：

`dp[i][j] = min(dp[i][j], dp[i-1][k] + maxD[k+1][j])`, 其中 i 为 分割的分数， i = 1 ~ d； j 为 已处理的工作的长度， j = 1 ~ n； k为在 [i - 1, j） 区间的分割点， k = i-1 ~ j-1。

maxD[i][j] 表示区间[i, j] 内的最大元素，可以在 O(N^2) 的时间内预计算出来。

### 代码

```cpp
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n)
            return -1;
        vector<vector<int>> maxD(n, vector<int>(n));
        vector<vector<int>> dp(d+1, vector<int>(n+1, 1001 * n));
        
        for(int i=0; i<n; i++) {
            maxD[i][i] = jobDifficulty[i];
            for(int j=i+1; j<n; j++)
                maxD[i][j] = max(maxD[i][j-1], jobDifficulty[j]);
        }
        
        dp[0][0] = 0;
        
        for(int i=1; i<=d; i++) {
            for(int j=i; j<=n; j++) {
                for(int k=i-1; k<j; k++) {
                    // k is split position (included in left range), compare dp[i][j] with the sum of dp[i-1][k] and max element in range [k+1, j]
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + maxD[k][j-1]);
                }
            }
        }
        
        return dp[d][n];
    }
};
```