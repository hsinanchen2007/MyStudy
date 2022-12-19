动态规划，需要针对0做特殊处理
```
int numDecodings(char * s){
    if (s == NULL) {
        return 1;
    }
    int len = strlen(s);
    int dp[len + 1];
    memset(dp, 0, sizeof(int) * (len + 1));

    dp[0] = 1;

    for (int i = 1;i <= len; i++) {
        int num1 = dp[i - 1];
        int num2 = 0;
        if (i > 1) {
            int alpha = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (alpha <= 26 && alpha >= 10) {
                num2 = dp[i - 2];
            }
        }
        if (s[i - 1] != '0') {
            dp[i] = num1 + num2;
        } else {
            dp[i] = num2;
        }
    }
    
    return dp[len];
}
```
