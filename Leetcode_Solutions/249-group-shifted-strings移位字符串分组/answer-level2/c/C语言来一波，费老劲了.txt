```
249：
struct map{
    int *sub;
    int sublen;
    char **word;
    int wordcnt;
};
int isExist(int *tmp, int len, struct map *wordmap, int wordmapcnt) 
{
    int i;
    int j;
    for (i = 0; i < wordmapcnt; i++) {
        if (len == wordmap[i].sublen) {
            for (j = 0; j < len; j++) {
                if (tmp[j] != wordmap[i].sub[j]) {
                    break; 
                }
            }
            if (j == len) {
                return i;
            }
        }
    }
    return -1;
}
char *** groupStrings(char ** strings, int stringsSize, int* returnSize, int** returnColumnSizes){
    char ***res = malloc(stringsSize * sizeof(char**));
    for (int i = 0; i < stringsSize; i++) {
        res[i] = (char**)malloc(stringsSize * sizeof(char*));
        for (int j = 0; j < stringsSize; j++) {
            res[i][j] = (char*)calloc(50, sizeof(char));
        }
    }
    struct map *wordmap = malloc(stringsSize * sizeof(struct map));
    int wordmapcnt = 0;
    for (int i = 0; i < stringsSize; i++) {
        int *tmp = calloc(strlen(strings[i]), sizeof(int));
        for(int j = 0; j < strlen(strings[i]) - 1; j++) {
            tmp[j] = (strings[i][j + 1] - strings[i][j] + 26) % 26;
        }
        int idx = isExist(tmp, strlen(strings[i]), wordmap, wordmapcnt);
        if (idx == -1) {
            wordmap[wordmapcnt].sub = calloc(strlen(strings[i]), sizeof(int));
            wordmap[wordmapcnt].sublen = strlen(strings[i]);
            memcpy(wordmap[wordmapcnt].sub, tmp, wordmap[wordmapcnt].sublen * sizeof(int));
            wordmap[wordmapcnt].word = (char**)malloc(stringsSize * sizeof(char*));
            wordmap[wordmapcnt].wordcnt = 0;
            wordmap[wordmapcnt].word[wordmap[wordmapcnt].wordcnt] = (char*)calloc(strlen(strings[i]) + 1, sizeof(char));
            strncpy(wordmap[wordmapcnt].word[wordmap[wordmapcnt].wordcnt], strings[i], strlen(strings[i]));
            wordmap[wordmapcnt].wordcnt++;
            wordmapcnt++;
        } else {
            wordmap[idx].word[wordmap[idx].wordcnt] = (char*)calloc(strlen(strings[i]) + 1, sizeof(char));
            strncpy(wordmap[idx].word[wordmap[idx].wordcnt], strings[i], strlen(strings[i]));
            wordmap[idx].wordcnt++;
        }
        free(tmp);
    }
    *returnSize = 0;
    *returnColumnSizes = (int*)calloc(wordmapcnt, sizeof(int));
    for (int i = 0; i < wordmapcnt; i++) {
        (*returnColumnSizes)[i] = wordmap[i].wordcnt;
        for (int k = 0; k < wordmap[i].wordcnt; k++) {
            strncpy(res[i][k], wordmap[i].word[k], strlen(wordmap[i].word[k]));
        }
    }
    *returnSize = wordmapcnt;
    for (int i = 0; i < wordmapcnt; i++) {
        free(wordmap[i].sub);
        for (int k = 0; k < wordmap[i].wordcnt; k++) {
            free(wordmap[i].word[k]);
        }
        free(wordmap[i].word);
    }
    free(wordmap);
    return res;
}
```
