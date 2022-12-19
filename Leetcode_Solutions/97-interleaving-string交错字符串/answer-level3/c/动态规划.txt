### 解题思路
关键列动态转移方程

### 代码

```c
bool isInterleave(char * s1, char * s2, char * s3){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    bool dp[128][128] = {false};

    if (len1 + len2 != len3) {
        return false;
    }
    
    dp[0][0] = true;
    for (int i = 1; i <= len1; i++) {
        if (s1[i - 1] == s3[i - 1] && dp[i - 1][0] == true) 
            dp[i][0] = true;
    }

    for (int j = 1; j <= len2; j++) {
        if (s2[j - 1] == s3[j - 1] && dp[0][j - 1] == true) 
            dp[0][j] = true;
             
    }

    for (int m = 1; m <= len1; m++) {
        for (int n = 1; n <= len2; n++) {
            if (s1[m - 1] == s3[m + n -1] && dp[m - 1][n] == true)
                dp[m][n] = true;
            
            if (s2[n - 1] == s3[m + n -1] && dp[m][n - 1] == true)
                dp[m][n] = true;
        }
    }

    return dp[len1][len2];
}
```