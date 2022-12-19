### 解题思路
dp[i] 表示已i结尾的最长有效字串；
dp[i]如果为‘（’，则dp[i]为0；
否则dp[i] 需要结合dp【i-1】的起始的前一个位置进行判断，如果匹配，则联合dp[i-1] dp[i-1 - dp[i-1]] + 2
需要判断索引是否符合哟啊求

### 代码

```c
int longestValidParentheses(char * s){
    if ((s == NULL) || (strlen(s) <= 1)) {
        return 0;
    }

    int len = strlen(s);
    int *dp = (int *)malloc(sizeof(int) * len);
    memset(dp, 0, sizeof(int)*len);

    dp[0] = 0;
    dp[1] = ((*s == '(') && (*(s+1) == ')')) ? 2 : 0;

    for (int i = 2; i < len; i++) {
        if ('(' == *(s+i)) {
            dp[i] = 0;
        }

        if (')' == *(s+i)) {
            int startIdx = i - 1 - dp[i-1];

            if ((startIdx >= 0) && ('(' == *(s+startIdx))) {
                dp[i] = dp[i-1] + 2 + ((startIdx - 1 > 0) ? dp[startIdx - 1] : 0);
            } else {
                dp[i] = 0;
            }
        }
    }
    
    int maxLength = 0;
    for (int i = 0; i < len; i++) {
        maxLength = (maxLength > dp[i]) ? maxLength : dp[i];
    }
    
    return maxLength;
}
```