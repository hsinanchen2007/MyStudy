最长公共字符串
`#define MIN(a, b) (((a) > (b)) ? (b) : (a))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
int found(char *str0, char ** strs, int strsSize)
{
    int i, j, k;
    int commLenMin = strlen(str0);
    for (i = 1; i < strsSize; i++) {
        int commLenTmp = 0;
        for (j = 0, k = 0; j < strlen(strs[i]); j++) {
            if (*(str0 + k) == *(strs[i] + j)) {
                k++;
            } else {
                commLenTmp = MAX(k, commLenTmp);
                k = 0;
            }
        }
        commLenTmp = MAX(k, commLenTmp);
        commLenMin = MIN(commLenMin, commLenTmp);
    }
    return commLenMin;
}

char *longestCommonPrefix(char ** strs, int strsSize)
{
    int i, j;
    int commLen;
    int commLenMax = 0;
    int flag = 0;

    if (strsSize == 0) {
        return "";
    }

    for (i = 0; i < strlen(strs[0]); i++) {
        commLen = found(strs[0] + i, strs, strsSize);
        if (commLen > commLenMax) {
            commLenMax = commLen;
            j = i;
        }
    }
    char *comm = (char *)malloc(commLenMax + 1);
    memcpy(comm, strs[0] + j, commLenMax);
    comm[commLenMax] = '\0';
    return comm;
}`

最长公共前缀
`#define MIN(a, b) (((a) > (b)) ? (b) : (a))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
int found(char *str0, char ** strs, int strsSize)
{
    int i, j, k;
    int commLenMin = strlen(str0);
    for (i = 1; i < strsSize; i++) {
        int commLenTmp = 0;
        for (j = 0, k = 0; j < strlen(strs[i]); j++) {
            if (*(str0 + k) == *(strs[i] + j)) {
                k++;
            } else {
                break;
            }
        }
        commLenMin = MIN(commLenMin, k);
    }
    return commLenMin;
}

char *longestCommonPrefix(char ** strs, int strsSize)
{
    int commLen;
    if (strsSize == 0) {
        return "";
    }
    commLen = found(strs[0], strs, strsSize);
    char *comm = (char *)malloc(commLen + 1);
    memcpy(comm, strs[0], commLen);
    comm[commLen] = '\0';
    return comm;
}`