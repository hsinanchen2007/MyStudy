### 解题思路
此处撰写解题思路

### 代码

```c
int dp[1001][1001];

int is_pa(char *s, int i, int j) {
    if (dp[i][j])
        return dp[i][j];

    if (i == j) {
        dp[i][j] = 1;
    } else if (i + 1 == j) {
        if (s[i] == s[j])
            dp[i][j] = 1;
        else
            dp[i][j] = -1;
    } else if (i > j) {
        dp[i][j] = -1;
    } else if (s[i] == s[j]) {
        dp[i][j] = is_pa(s, i + 1, j - 1);
    } else
        dp[i][j] = -1;

    return dp[i][j];
}


char * longestPalindrome(char * s){
    int len, i, j;
    int max_s, max_e;

    if (!s || (len = strlen(s)) <= 1)
        return s;

    max_s = max_e = 0;
    memset(dp, 0, 1001 * 1001 * sizeof(int));
    for (i = 0; i < len; ++i)
        for (j = i; j < len; ++j) {
            (void)is_pa(s, i, j);
            if (dp[i][j] == 1 && max_e - max_s < j - i) {
                max_s = i;
                max_e = j;
            }
        }

    s[max_e + 1] = '\0';
    return s + max_s;
}
```