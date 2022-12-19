int MIN(int a, int b) {
    return (a < b ? a : b);
}

int min(int a, int b, int c) {
    return MIN(a, MIN(b, c));
}

int minDistance(char * word1, char * word2){
    int m = strlen(word1), n = strlen(word2);
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(int)*(m + 1)*(n + 1));
    // base case 
    for (int i = 1; i <= m; i++)
        dp[i][0] = i;
    for (int j = 1; j <= n; j++)
        dp[0][j] = j;
    // 自底向上求解
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else               
                dp[i][j] = min(
                    dp[i - 1][j] + 1,
                    dp[i][j - 1] + 1,
                    dp[i-1][j-1] + 1
                );
    // 储存着整个 s1 和 s2 的最小编辑距离
    return dp[m][n];
}