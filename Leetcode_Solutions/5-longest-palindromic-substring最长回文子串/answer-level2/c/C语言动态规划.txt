char * longestPalindrome(char * s){
    if (s == NULL || s[0] == '\0') {
        return "";
    }
	int len = strlen(s);
    int dp[len][len];
    int max = 1;
    int left = 0;
    int right = 0;
	int i;
	int j;

    for (i = 0; i < len; i++) {
        dp[i][i] = 1;
    }

    for (i = len-1; i >= 0; i--) {
        for (j = i+1; j < len; j++) {
            if (j - i > 1) {
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            } else {
                dp[i][j] = (s[i] == s[j]);
            }
            
            if (dp[i][j]) {
                if (max < j-i+1) {
                    max = j-i+1;
                    left = i;
                    right = j;
                }
            }
        }
    }

    s[right+1] = '\0';
    s += left;
    return s;
}