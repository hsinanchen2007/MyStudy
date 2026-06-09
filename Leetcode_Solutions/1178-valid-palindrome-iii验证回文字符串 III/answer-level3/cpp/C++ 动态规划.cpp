简化为寻找字符串s及其反向字符串的最长公共子序列，例如 **a**b**cd**e**ca** 和 **ac**e**dc**b**a**
```
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int len = s.size();
        vector<vector<int>> dp(len+1, vector<int>(len+1, 0));
        
        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= len; j++) {
                if (s[i - 1] == s[len - j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return (dp[len][len] + k >= len);
    }
};
```
