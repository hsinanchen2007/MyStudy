注意点1：构造最长公共子序列的过程稍加改造即可用于构造最短公共超序列，无须分步构造
注意点2：不可在动态规划过程中记录最长公共子序列的值，否则算法时间复杂度会退化为O(n^3)

```
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size(), lcd, i, j, dp[1001][1001] = {0};
        string ans;
        //动态规划计算最长公共子序列的长度
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1] && dp[i - 1][j - 1] + 1 > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        //构造最短公共超序列
        for (i = n, j = m, lcd = dp[n][m]; i || j; ) {
            if (i && j && str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                lcd--, i--, j--;
            }
            else {
                //若此处只修改i、j的值但不记录在ans中，则ans最后记录的为最长公共子序列
                if (j && dp[i][j - 1] == lcd) ans.push_back(str2[--j]);
                else ans.push_back(str1[--i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
