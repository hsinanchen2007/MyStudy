```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct nodemap {
    char *beg;
    char *end;
    char *sub;    
};
void GetHeadWord(char* in, char *out)
{
    int len = strlen(in);
    int i = 0;
    while (i < len && in[i] != ' ') {
        out[i] = in[i];
        i++;
    }
}
void GetTailWord(char* in, char *out)
{
    char tmp[100] = {'\0'};
    int len = strlen(in);
    int i = len - 1;
    int cnt = 0;
    while (i >= 0 && in[i] != ' ') {
        tmp[cnt] = in[i];
        i--;
        cnt++;
    }
    for (int k = 0; k < cnt; k++) {
        out[k] = tmp[cnt - 1 - k];
    }
}
void GetSubWord(char* in, char *out, int begIdx)
{
    int len = strlen(in);
    int i = begIdx;
    int cnt = 0;
    while (i < len) {
        out[cnt] = in[i];
        i++;
        cnt++;
    }
}
int isExist(char **res, int cnt, char *s)
{
    for (int i = 0; i < cnt; i++) {
        if ((strlen(res[i]) == strlen(s)) && (strncmp(res[i], s, strlen(s)) == 0)) {
            return 1;
        }
    }
    return 0;
}
int cmp(const void *arg1, const void *arg2)
{
    char *a = *(char**)arg1;
    char *b = *(char**)arg2;
    return strcmp(a, b);
}
char ** beforeAndAfterPuzzles(char ** phrases, int phrasesSize, int* returnSize){
    struct nodemap *strMap = malloc(100 * sizeof(struct nodemap));
    char *tmp = calloc(100, sizeof(char));
    for (int i = 0; i < phrasesSize; i++) {
        memset(tmp, 0, 100);
        GetHeadWord(phrases[i], tmp);
        int tmpLen = strlen(tmp);
        int begIdx = tmpLen;
        strMap[i].beg = (char*)calloc(tmpLen + 1, sizeof(char));
        strncpy(strMap[i].beg, tmp, tmpLen);
        //printf("[%d]beg: %s\n", i, strMap[i].beg);
        memset(tmp, 0, 100);
        GetTailWord(phrases[i], tmp);        
        tmpLen = strlen(tmp);
        strMap[i].end = (char*)calloc(tmpLen + 1, sizeof(char));
        strncpy(strMap[i].end, tmp, tmpLen);
        //printf("[%d]end: %s\n", i, strMap[i].end);
        memset(tmp, 0, 100);
        GetSubWord(phrases[i], tmp, begIdx);        
        tmpLen = strlen(tmp);
        strMap[i].sub = (char*)calloc(tmpLen + 1, sizeof(char));
        strncpy(strMap[i].sub, tmp, tmpLen);
        //printf("[%d]sub: %s\n", i, strMap[i].sub);
    }
    char **res = malloc(10000 * sizeof(char*));
    int resCnt = 0;
    char *s = (char*)calloc(10240, sizeof(char));
    for(int i = 0; i < phrasesSize; i++) {
        for(int j = 0; j < phrasesSize; j++) {
            if ((strlen(strMap[i].end) == strlen(strMap[j].beg)) && (strncmp(strMap[i].end, strMap[j].beg, strlen(strMap[i].end)) == 0) && (i != j)) {
                memset(s, 0, 10240);
                strncat(s, phrases[i], strlen(phrases[i]));
                strncat(&(s[strlen(phrases[i])]), strMap[j].sub, strlen(strMap[j].sub));
                //printf("s: %s\n", s);
                if (isExist(res, resCnt, s) == 0) {
                    res[resCnt] = (char*)calloc(strlen(s) + 1, sizeof(char));
                    strncpy(res[resCnt], s, strlen(s));
                    //printf("res[%d]: %s\n", resCnt, res[resCnt]);
                    resCnt++;
                }
            }
        }
    }
    free(tmp);
    free(s);
    qsort(res, resCnt, sizeof(char*), cmp);
    *returnSize = resCnt;
    return res;
}

```
