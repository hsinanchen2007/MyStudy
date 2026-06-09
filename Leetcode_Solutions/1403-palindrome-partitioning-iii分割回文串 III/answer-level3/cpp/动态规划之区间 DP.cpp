`dp(i, j, k)` 表示将子串[i, j]分割成 k 个的最优结果
转移方程：`dp(i, j, k) = min{dp(i, m, 1) + dp(m + 1, j, k - 1)}`

```
class Solution {
public:
    int palindromePartition(string s, int k) {
        vector<vector<vector<long>>> dp(s.size(), vector<vector<long>>(s.size(), vector<long>(k + 1, INT_MAX)));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i][1] = 0;
            for (int j = 1; j + i < s.size() && i - j >= 0; j++) {
                if (s[i - j] == s[i + j])
                    dp[i - j][i + j][1] = 0;
                else 
                    break;
            }
        }
        for (int i = s.size() - 2; i >= 0; i--) {
            dp[i][i + 1][1] = s[i] == s[i + 1] ? 0 : 1;
            for (int j = i + 1; j < s.size(); j++) {
                dp[i][j][1] = (j == i + 1 ? 0 : dp[i + 1][j - 1][1]) + (s[i] == s[j] ? 0 : 1);
                for (int l = 2; l <= k; l++) {
                    for (int m = i; m < j; m++) {
                        dp[i][j][l] = std::min(dp[i][j][l], dp[i][m][1] + dp[m + 1][j][l - 1]);
                    }
                }
            }
        }
        return dp[0][s.size() - 1][k];
    }
};
```
