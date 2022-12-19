```
char buf[2000][200];
char * findReplaceString(char * S, int* indexes, int indexesSize, char ** sources, int sourcesSize, char ** targets, int targetsSize)
{
    char *res = (char *)calloc(100000, sizeof(char));
    memset(buf, 0, sizeof(buf));
    // 1.依次将第一个字符放进buf的第一列
    for (int i = 0; i < strlen(S); i++) {
        buf[i][0] = S[i];
    }
    for (int i = 0; i < indexesSize; i++) {
        int sourceLen = strlen(sources[i]);
        int idx = indexes[i];
        if (strncmp(S + idx, sources[i], sourceLen) == 0) {
            // 2.如果匹配成功则替换掉buf中的当前行
            strcpy(buf[idx], targets[i]);
            // 3.同时清空后面的行
            for (int k = 1; k < sourceLen; k++) {
                buf[idx + k][0] = '\0';
            }
        }
    }
    // 4.拼接返回结果
    for (int i = 0; i < strlen(S); i++) {
        strcat(res, buf[i]);
    }
    return res;
}
```
