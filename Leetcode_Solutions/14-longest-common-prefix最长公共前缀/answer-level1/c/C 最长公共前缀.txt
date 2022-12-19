1.找最短字符串idx，最大公共前缀长度不超过最短字符长度m。
2.将最短字符串与其他字符串对比，不同则快速退出，刷新最短匹配长度m。
3.返回最短字符串前m个字符。

char * longestCommonPrefix(char ** strs, int strsSize){
    int iMinIdx = 0;
    int minLen = INT_MAX;
    int cur = 0;
    int i, j;
    char *retStr = NULL;

    if (!strs || strsSize==0) {
        retStr = (char*)malloc(1);
        retStr[0] = '\0';
        return retStr;
    }

    // 找最小长度
    for (i = 0; i < strsSize; ++i) {
        cur = strlen(strs[i]);
        if (cur < minLen) {
            minLen = cur;
            iMinIdx = i;
        }
    }

    //找最大公共匹配
    for (i = 0; i < strsSize; ++i) {
        for (j = 0; j < minLen; ++j) {
            if (strs[i][j] != strs[iMinIdx][j]) {
                break;
            }
        }
        if (j < minLen) {
            minLen = j;
        }
    }
    //printf("%d %s",minLen,  strs[iMinIdx]);

    retStr = (char*)malloc(minLen + 1);
    retStr[minLen] = '\0';
    strncpy(retStr, strs[iMinIdx], minLen);

    return retStr;
}