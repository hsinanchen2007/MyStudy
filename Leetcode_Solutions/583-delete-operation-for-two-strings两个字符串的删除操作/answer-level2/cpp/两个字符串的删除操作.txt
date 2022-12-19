### 解题思路
动态规划
字符串长度分别为n1, n2, 最长公共子序列长度为m，那么res ＝ n1 + n2 - 2m;

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(1+n1, vector<int>(1+n2, 0));
        for(int i = 0; i < n1; ++i) {
            for(int j = 0; j < n2; ++j) {
                if (word1[i] == word2[j]) {
                    dp[i+1][j+1] = 1 + dp[i][j];
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j],  dp[i][j+1]);
                }
            }
        }
        return n1+n2-2*dp[n1][n2];
    }
};
```