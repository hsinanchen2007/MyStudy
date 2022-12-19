![leetcode-639.jpg](https://pic.leetcode-cn.com/49ccff96a6b416aebf50f1a8295f8f7a347b1fe1ea72569597f96f79c2cc1082-leetcode-639.jpg)





int numDecodings(char * s){
    int ret = 0;
    int strLen = strlen(s);
    if (strLen < 1) {
        return 0;
    }
    
    //long dp[120000] = {0};
    int size = (strLen + 1) * sizeof(long);
    long *dp = (long *)malloc(size);
    if (dp == NULL) {
        return 0;
    }
    
    memset(dp, 0, size);
    
    dp[0] = 1;// 保留dp[0]用于辅助记录有2个数字时的可能编码情况
    if ('1' <= s[0] && s[0] <= '9') {
        dp[1] = 1;
    } else if (s[0] == '*') {
        dp[1] = 9;
    } else {
        return 0;
    }
    
    for (int i = 2; i <= strLen; i++) {
        if (s[i - 1] == '*' || ('0' <= s[i - 1] && s[i - 1] <= '9')) {
            if (s[i - 2] == '0') {
                if (s[i - 1] == '*') {
                    dp[i] = 9 * dp[i - 1];
                } else if (s[i - 1] == '0') {
                    return 0;
                } else {
                    dp[i] = dp[i - 1];
                }
            } else if (s[i - 2] == '1') {
                if (s[i - 1] == '*') {
                    dp[i] = 9 * dp[i - 1] + 9 * dp[i - 2];
                } else if (s[i - 1] == '0') {
                    dp[i] = dp[i - 2];
                } else {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
            } else if (s[i - 2] == '2') {
                if (s[i - 1] == '*') {
                    dp[i] = 9 * dp[i - 1] + 6 * dp[i - 2];
                } else if (s[i - 1] == '0') {
                    dp[i] = dp[i - 2];
                } else if ('1' <= s[i - 1] && s[i - 1] <= '6'){ 
                    dp[i] = dp[i - 1] + dp[i - 2];
                } else {
                    dp[i] = dp[i - 1];
                }
            } else if ('3' <= s[i - 2] && s[i - 2] <= '9') {
                if (s[i - 1] == '*') {
                    dp[i] = 9 * dp[i - 1];
                } else if (s[i - 1] == '0') {
                    return 0;
                } else {
                    dp[i] = dp[i - 1];
                }
            } else if (s[i - 2] == '*'){
                if (s[i - 1] == '*') {
                    dp[i] = 9 * dp[i - 1] + (9 + 6) * dp[i - 2];
                } else if (s[i - 1] == '0') {
                    dp[i] = 2 * dp[i - 2];
                } else if ('1' <= s[i - 1] && s[i - 1] <= '6'){
                    dp[i] = dp[i - 1] + 2 * dp[i - 2];
                } else {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
            }
        } else {
            return 0;
        }
        
        if (dp[i] >= 1000000007) {
            dp[i] %= 1000000007;
        }
    }
    
    ret = (int)dp[strLen];
    free(dp);
    
    return ret;
