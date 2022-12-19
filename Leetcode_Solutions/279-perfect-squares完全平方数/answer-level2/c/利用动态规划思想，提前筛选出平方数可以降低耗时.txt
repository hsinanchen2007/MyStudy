#define MIN(a, b) ((a > b) ? b : a)

int numSquares(int n){
    int i = 0;
    int j = 0;
    int *dp;
    if (n <= 0) {
        return 0;
    }
    if (((int)sqrt(n) * (int)sqrt(n)) == n) {
        return 1;
    }
    dp = (int *)malloc((n + 1) * sizeof(int));
    
    for (i = 0; i <= n; i++) {
        dp[i] = i;
    }    
    
    for (i = 2; i <= n; i++) {
        for (j = 1; j * j <= i; j++) {
            dp[i] = MIN(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}
