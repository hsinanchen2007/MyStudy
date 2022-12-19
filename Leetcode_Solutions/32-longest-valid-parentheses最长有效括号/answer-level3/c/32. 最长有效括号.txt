### 解题思路
此处撰写解题思路

### 代码

```c
int longestValidParentheses(char * s){
    int len, i, tmp, maxLen = 0;
    int *dp = NULL;

    if (!s || (len = strlen(s)) < 2)
        return 0;

    dp = calloc(len, sizeof(int));
    if (!dp) {
        return -1;
    }

    for (i = 1; i < len; ++i) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                tmp = i - 2;
                dp[i] = 2 + dp[tmp < 0 ? 0 : tmp];
            } else if (s[i - 1] == ')') {
				tmp = i - 1 - dp[i - 1];
                if (tmp >= 0 && s[tmp] == '(') {
                    tmp = i - 2 - dp[i-1];
                    dp[i] = dp[i - 1] + 2 + dp[tmp < 0 ? 0 : tmp];
                }
            }
            if (dp[i] > maxLen)
                maxLen = dp[i];
        }
    }
    
    return maxLen;
}
```