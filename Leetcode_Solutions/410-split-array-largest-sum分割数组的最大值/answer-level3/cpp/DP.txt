### 解题思路

DP

### 代码

```cpp
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        vector<long> sum(n+1);
        
        for(int i=0; i<n; i++) {
            sum[i+1] = sum[i] + nums[i];
        }
        
        dp[0][0] = 0;
        // 枚举前i位
        for(int i=1; i<=n; i++) {
            // 枚举 分割j段
            for(int j=1; j<=m; j++) {
                // 枚举进一步分割
                for(int k=0; k<i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j-1], (int)(sum[i] - sum[k])));
                }
                // cout << i << "," << j << "," << dp[i][j] << endl;
            }
        }
        
        return dp[n][m];
    }
};
```

或者：

```cpp
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long>> dp(n+1, vector<long>(m+1));
        
        dp[0][1] = nums[0];
        // 枚举前i位
        for(int i=1; i<n; i++) {
            // j = 1 为 sum 数组
            dp[i][1] = dp[i-1][1] + nums[i];
            // 枚举 分割j段
            for(int j=2; j<=min(i+1, m); j++) {
                dp[i][j] = INT_MAX;
                // 枚举进一步分割
                for(int k=0; k<i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j-1], dp[i][1] - dp[k][1]));
                }
                cout << i << "," << j << "," << dp[i][j] << endl;
            }
        }
        
        return dp[n-1][m];
    }
};
```