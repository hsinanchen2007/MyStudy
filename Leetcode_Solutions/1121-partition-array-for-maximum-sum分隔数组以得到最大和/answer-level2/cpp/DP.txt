### 解题思路

对每个位置i，枚举长度 j = 1 ~ K，看是否能更新到数组和更大。

### 代码

```cpp
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n+1);
        dp[0] = 0;
        
        for(int i=1; i<=n; i++) {
            dp[i] = 0;
            for(int j = 1; j <= min(i, K); j++) {
                int x = *max_element(A.begin() + i - j, A.begin() + i);
                dp[i] = max(dp[i], dp[i - j] + x * j);
            }
            // cout << i << ":" << dp[i] << endl;
        }
        
        return dp[n];
    }
};
```