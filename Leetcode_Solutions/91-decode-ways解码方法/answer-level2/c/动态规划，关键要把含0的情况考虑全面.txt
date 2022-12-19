### 解题思路
要把含0的情况考虑全面

### 代码

```c
int numDecodings(char * s){
    int len = strlen(s);
    if (len < 1) {
        return 0;
    }
    
    if (s[0] == '0') {
        return 0;
    }

    if (len == 1) {
        return 1;
    }

    int dp[len];
    dp[0] = 1;
    
    char buf[8] = {'\0'};
    buf[0] = s[0];
    buf[1] = s[1];

    for (int i = 1; i < len; i++) {
        buf[0] = s[i - 1];
        buf[1] = s[i];

        if (s[i] == '0'){
            if (atoi(buf) <= 26 && atoi(buf) > 0) {
                if (i > 1) {
                    dp[i] = dp[i - 2];
                } else {
                    dp[i] = 1;
                }
            } else {
                //printf("test2\n");
                return 0;
            }
        } else {
            if (atoi(buf) > 26 || s[i - 1] == '0') {
                dp[i] = dp[i - 1];
            } else {
                if (i > 1) {
                    dp[i] = dp[i - 1] + dp[i - 2];
                } else {
                    dp[i] = 2;
                }
            }
        }
    }

    return dp[len - 1];
}
```