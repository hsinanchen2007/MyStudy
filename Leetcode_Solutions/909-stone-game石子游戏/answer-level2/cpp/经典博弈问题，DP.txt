### 解题思路一
DP公式为：
dp[i][j][0] = max{x[i]+dp[i+1][j][1], dp[i][j-1][1]+x[j]} // 先手取左/右中最大的
dp[i][j][1] = dp[i+1][j][0] // 如果先手取左边
            or dp[i][j-1][0] // 如果先手取右边
 
### 代码一

```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2)));
        for(int i=0; i<n; i++) {
            dp[i][i][0] = piles[i]; // first
            dp[i][i][1] = 0;        // second
        }
        for(int k=1; k<n; k++) { // offset
            for(int i=0; i+k<n; i++) { // diag
                int j = i + k;
                int left = dp[i+1][j][1] + piles[i];
                int right = dp[i][j-1][1] + piles[j];
                if(left > right) {
                    dp[i][j][0] = left;              // first
                    dp[i][j][1] = dp[i+1][j][0];     // second
                } else {
                    dp[i][j][0] = right;             // first
                    dp[i][j][1] = dp[i][j-1][0];     // second
                }
            }
        }
        return dp[0][n-1][0] > dp[0][n-1][1];
    }
};
```

### 解题思路二

MinMax

### 代码二

```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = std::accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> dp(n, vector<int>(n));
        

        for(int len=1; len<=n; len++) {
            for(int i=0; i+len-1<n; i++) {
                int j = i + len - 1;
                if(len == 1) {
                    dp[i][j] = piles[i];
                } else {
                    dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1] > 0;
    }
};
```