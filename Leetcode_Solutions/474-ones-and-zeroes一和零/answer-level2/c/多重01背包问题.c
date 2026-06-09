```
#define max(a, b) a > b ? a : b;
#define min(a, b) a < b ? a : b;

int findMaxForm(char ** strs, int strsSize, int m, int n)
{
    int count0[strsSize];
    int count1[strsSize];
    memset(&count0, 0, sizeof(int) * strsSize);
    memset(&count1, 0, sizeof(int) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        int len = strlen(strs[i]);
        int c0 = 0;
        for (int j = 0; j < len; j++) {
            if (strs[i][j] == '0') {
                c0++;
            }
        }
        count0[i] = c0;
        count1[i] = len - c0;
    }
    int dp[m + 1][n + 1];
    memset(&dp, 0, sizeof(int) * (m + 1) * (n + 1));
    for (int i = 0; i < strsSize; i++) {
        for (int j = m; j >= count0[i]; j--) {
            for (int k = n; k >= count1[i]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - count0[i]][k - count1[i]] + 1);
            }
        }
    }
    return dp[m][n];
}
```
