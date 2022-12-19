### 解题思路
动态规划，找出第一次最大的DP值对应字符的位置，感觉是个暴力解法

### 代码

```c
int Max(int a, int b)
{
    return (a > b) ? a : b;
}

char * longestPalindrome(char * s){
    int len = strlen(s);
    if (len <= 1) {
        return s;
    } 
    int dp[len][len];

    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }

    int max = 1;
    int h = 0;
    int t = 0;
 
    for (int m = 1; m < len; m++) {
        for (int n = 0; n < len - m; n++) {
            if (m == 1) {
                if (s[n] == s[n + m]) {
                    dp[n][n + m] = 2;
                    max = dp[n][n + m];
                    h = m;
                    t = n;
                } else {
                    dp[n][n + m] = 1;
                }
                continue;          
            }

            if (s[n] == s[n + m] && dp[n + 1][n + m - 1] == m - 1) {
                dp[n][n + m] = dp[n + 1][n + m - 1] + 2;
            } else {
                dp[n][n + m] = Max(dp[n][n + m - 1], dp[n + 1][n + m]);
            }
            if (dp[n][n + m] > max) {
                max = dp[n][n + m];
                h = m;
                t = n;
            }
        }    
    }

    char *buf = (char *)malloc(sizeof(char) * (h + 2));
    memset(buf, 0, sizeof(char) * (h + 2));
    memcpy(buf, (s + t), sizeof(char) * (h + 1));
    
    return buf;
}
```