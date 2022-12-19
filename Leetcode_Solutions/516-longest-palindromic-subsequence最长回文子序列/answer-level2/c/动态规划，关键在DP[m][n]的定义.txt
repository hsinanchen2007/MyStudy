### 解题思路
关键点
            if (s[m] == s[n]) {
                dp[m][n] = 2 + dp[m + 1][n - 1]; 
            } else {
                dp[m][n] = Max(dp[m + 1][n], dp[m][n - 1]);
            }

### 代码

```c
int Max(int a, int b) {
    return (a > b) ? a : b;
}

int longestPalindromeSubseq(char * s){
    int len = strlen(s);
    if (len <= 0) {
        return 0;
    }
    
    int dp[1000][1000] = {0};
    
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
        if (s[i] == s[i + 1] && i < len - 1) {
            dp[i][i + 1] = 2;
        } 

        if (s[i] != s[i + 1] && i < len - 1) {
            dp[i][i + 1] = 1;
        }    

    }
    
    for (int j = 2; j < len; j++) {
        int m = 0;
        for (int n = m + j; n < len; n++) {
            if (s[m] == s[n]) {
                dp[m][n] = 2 + dp[m + 1][n - 1]; 
            } else {
                dp[m][n] = Max(dp[m + 1][n], dp[m][n - 1]);
            }
            m++;
        }
    }

    return dp[0][len - 1];

}
```