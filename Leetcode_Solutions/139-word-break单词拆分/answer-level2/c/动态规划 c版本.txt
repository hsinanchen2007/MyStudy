没用hashset这种高级结构，时间复杂度为O(N4)，还好leetcode给面子，测试用例的数据量不大。

bool wordContain(char *s, int from, int to, char ** wordDict, int wordDictSize){
    char dst[256] = {0};
    int i;
    for (i = 0; i <= to - from; i++) {
        dst[i] = s[from+i];
    }
    for (i = 0; i < wordDictSize; i++) {
        if (strcmp(dst, wordDict[i]) == 0)
            return true;
    }
    return false;
}
bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int i, j;
    int len;
    int res;
    char *dp;

    if (s == NULL || wordDict == NULL || wordDictSize <= 0)
        return false;

    len = strlen(s);
    dp = (char *)calloc(1, (len+1) * sizeof (char));
    dp[0] = 1;
    for (i = 1; i <= len; i++) {
        for (j = 0; j < i; j++) {
            // dp[i]对应s[i-1]
            // s  -  catsandog
            // dp - 0001111100
            if (dp[j] && wordContain(s, j, i-1, wordDict, wordDictSize)) {
                dp[i] = 1;
            }
        }
    }
    res = dp[len];
    free(dp);
    return res == 1;
}