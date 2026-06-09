回文子序列：
定义dp[i][j]是指字符串i-j之间的最长子序列。

那么有如下的处理函数：
如果i = j, dp[i][j] = 1;
如果s[i] = s[j]，dp[i][j] = dp[i + 1][j - 1] + 2
如果s[i] != s[j]，那么dp的选择取决于dp[i][j-1]和dp[i+1][j]之间的最大值,即max(dp[i][j-1], dp[i+1][j])

```
int longestPalindromeSubseq(char * s)
{
    if (s == NULL || strlen(s) == 0) {
        return 0;
    }
    
    size_t len = strlen(s);
    int **dp = (int **)malloc(sizeof(int *) * len);
    if (dp == NULL) {
        return 0;
    }

    memset(dp, 0, sizeof(int *) * len);
    for (int i = 0; i < len; ++i) {
        dp[i] = (int *)malloc(sizeof(int) * len);
        memset(dp[i], 0, sizeof(int) * len);
        dp[i][i] = 1;
    }

    for (int i = len - 1; i >= 0; --i) {
        for (int j = i + 1; j < len; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = dp[i + 1][j] > dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1];
            }
        }
    }

    int ret = dp[0][len - 1];
    for (int i = 0; i < len; ++i) {
        free(dp[i]);
    }
    free(dp);

    return ret;
}
```



