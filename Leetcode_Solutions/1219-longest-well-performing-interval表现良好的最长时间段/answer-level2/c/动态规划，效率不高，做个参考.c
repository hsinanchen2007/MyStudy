```
int longestWPI(int* hours, int hoursSize){
    int* dp;
    int i, j;
    dp = (int*)malloc(hoursSize * sizeof(int));
    int max = 0;
    for (i = 0; i < hoursSize; i++) {
        if (hours[i] > 8) {
            hours[i] = 1;
            dp[i] = 1;
            max = 1;
        } else {
            hours[i] = -1;
            dp[i] = -1;
        }
    }
    int len;
    for (len = 1; len < hoursSize; len++) {
        for (j = 0; j < hoursSize - len; j++) {
            dp[j] = dp[j] + hours[j + len];
            if (dp[j] > 0) {
                if (len + 1 > max) {
                    max = len + 1;
                }
            }
        }
    }
    free(dp);
    return max;
}
```
依长度依次计算表现良好的最长时间段，记录最大值。
