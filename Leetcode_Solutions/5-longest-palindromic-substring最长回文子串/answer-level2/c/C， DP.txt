### 解题思路
1、定义dp[i][j] 为从i下标到j下标是否为回文串
2、分两种情况，当前下标的两个字符相同，其状态取决自己的前一个状态的字符串是否回文；如果不相同肯定不是回文串

### 代码

```c

/* 定义dp[i][j] 为从i下标到j下标是否为回文串 */

char * longestPalindrome(char * s){
    int len = strlen(s) + 1;
    
    if (len < 2) {
        return s;
    }

    /* 定义dp[i][j] 为从i下标到j下标是否为回文串 */
    int dp[len][len];
    memset(dp, 0, len * len);
    int maxLen = 1;
    int start = 0;
    
    for (int j = 1; j < len; j++ ) {
        for (int i = 0; i < j; i++) {
            if (s[i] == s[j]) {
                if (j - i < 3) { /*字符相同，且小于3，最多两个，就是其本身，肯定回文*/
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j - 1]; /* 当前状态取决于子串状态 */
                }
            } else {
                dp[i][j] = 0;
            }

            if (dp[i][j] == 1) { /* 回文串，记录下标和长度 */
                int curLen = j - i + 1;
                if (curLen > maxLen) {
                    maxLen = curLen;
                    start = i;
                }
            }
        }
    }

    char *result = malloc(maxLen + 1);
    for (int i = 0; i < maxLen; i++) { /* 按起始和长度拷贝字符串 */
        result[i] = s[start];
        start++;
    }
    result[maxLen] = '\0';
    return result;
}
```