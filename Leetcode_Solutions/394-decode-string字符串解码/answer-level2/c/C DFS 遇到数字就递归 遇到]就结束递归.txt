DFS思路，跟C点赞第一的兄弟比了一下，差别在于我的DFS是从数字开始，他的是从[开始，代码相差很多

```
#define TMP_SLEN 5000
int getNumFromS(char *s, int *pos)
{
    int num = 0;
    int i = *pos;
    while (s[i] != '[') {
        num = num * 10 + s[i] - '0';
        i++;
    }
    *pos = i;
    return num;
}

char *dfs(char *s, int *pos, int *rtnSLen) {
    int num = getNumFromS(s, pos);// 取出重复的次数k
    int k = *pos + 1; // 跳过数字后面的[

    char *sTmp = (char *)calloc(TMP_SLEN, sizeof(char));
    int sTmpLen = 0;
    while (s[k] != ']') {
        if ((s[k] >= '0') && (s[k] <= '9')) {
            int subSLen = 0;
            char *subS = dfs(s, &k, &subSLen); // 求内部嵌套的子串
            strcpy(&sTmp[sTmpLen], subS);  // 嵌套子串展开到本层子串中
            sTmpLen += subSLen;
            free(subS);
        } else {
            sTmp[sTmpLen] = s[k];
            sTmpLen++;
            k++;
        }
    }

    /* 字符串重复次数处理 */
    char *sOut = (char *)calloc(TMP_SLEN, sizeof(char));
    int sOutLen = 0;
    for (int i = 0; i < num; i++) {
        strcat(&sOut[sOutLen], sTmp);
        sOutLen += sTmpLen;
    }
    sOut[sOutLen] = '\0';
    free(sTmp);
    *pos = k + 1;
    *rtnSLen = sOutLen;
    //printf("num=%d, pos=%d, rtnSLen=%d, rtn=%s\n", num, *pos, *rtnSLen, sOut);
    return sOut;
}


char * decodeString(char * s){
    int sLen = strlen(s);
    if (sLen < 4) {
        return s;
    }
    char *sTmp = (char *)calloc(TMP_SLEN, sizeof(char));
    int sTmpLen = 0;
    int k = 0;
    for (k = 0; k < sLen;) {
        if ((s[k] >= '0') && (s[k] <= '9')) {
            //printf("k=%d:\n", k);
            int subSLen = 0;
            char *subS = dfs(s, &k, &subSLen); // 求内部嵌套的子串
            int tmpInt = strcpy(&sTmp[sTmpLen], subS);  // 嵌套子串展开到本层子串中
            sTmpLen += subSLen;
            free(subS);
        } else {
            sTmp[sTmpLen] = s[k];
            sTmpLen++;
            k++;
        } 
    }
    return sTmp;
}
```
