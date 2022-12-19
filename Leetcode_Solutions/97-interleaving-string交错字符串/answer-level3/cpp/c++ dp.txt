### 解题思路
dp[i][j] = true表示s1[0, i],s2[0, j]可以交错组成s3[0, i+j]；
dp[0][0] = true
dp[i][j] = s2[j-1] == s3[i+j-1] && dp[i][j-1] || s1[i-1] == s3[i+j-1] && dp[i-1][j]
注意i = 0和j = 0时的特殊处理
### 代码

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1));
        dp[0][0] = true;
        for (int i = 0; i <= s1.size(); ++i) {
            for (int j = 0; j <= s2.size(); ++j) {
                if (!i && !j) continue;
                int tmp1 = 0, tmp2 = 0;
                if (j) tmp1 = s2[j-1] == s3[i+j-1] && dp[i][j-1];
                if (i) tmp2 = s1[i-1] == s3[i+j-1] && dp[i-1][j];
                dp[i][j] = tmp1 || tmp2;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
```