char * longestPalindrome(char * s){
    int len = strlen(s);
    int dp[1000][1000];
 
    int start = 0;
    int end = 0;
    int max = 1;
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }
    
    for (int i = len - 1; i >= 0; i--) {
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                if (i + 1 == j) {
                    dp[i][j] = 2;
                } else {
                    if (dp[i+1][j-1] == 0) {
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                }
                
                if (max <= dp[i][j]) {
                    start = i;
                    end = j;
                    max = dp[i][j];
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    
    int rlen = end - start + 1;
    char *result = malloc(sizeof(char)*(rlen+1));
    memcpy(result, s+start, sizeof(char)*rlen);
    result[rlen] = 0;
    return result;
}