最简单直接的解法，正反方向映射检查一下即可，还有优化空间

```
int flag_matrix[255];


void initMatrix(){
    memset(flag_matrix, 0, sizeof(int) * 255);
}

int checkSameType(char *pattern, char *words, int size){
    initMatrix();

    for (int i=0; i<size; i++) {
        char p = pattern[i];
        char n = words[i];

        if (flag_matrix[p] == 0) {
            flag_matrix[p] = n;
            continue;
        } else if (flag_matrix[p] != n) {
            return 0;
        }
    }

    initMatrix();

    for (int i=0; i<size; i++) {
        char n = pattern[i];
        char p = words[i];

        if (flag_matrix[p] == 0) {
            flag_matrix[p] = n;
            continue;
        } else if (flag_matrix[p] != n) {
            return 0;
        }
    }

    return 1;
}

char ** findAndReplacePattern(char ** words, int wordsSize, char * pattern, int* returnSize){
    int str_len = strlen(pattern);

    char **rec = (char **)malloc(sizeof(char *) * 50);
    *returnSize = 0;

    for (int i=0; i<wordsSize; i++) {
        if (str_len != strlen(words[i])) {
            continue;
        }
         
        if (checkSameType(pattern, words[i], str_len)) {
            rec[*returnSize] = (char *)malloc(sizeof(char) * (str_len + 1));
            memcpy(rec[*returnSize], words[i], sizeof(char) * (str_len + 1));
            *returnSize += 1;
        }

    }

    return rec;
}
```
