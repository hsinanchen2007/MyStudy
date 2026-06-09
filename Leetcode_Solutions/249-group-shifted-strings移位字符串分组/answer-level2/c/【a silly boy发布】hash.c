```
#define MAXSIZE 256
#define ALPHASIZE 26

struct HashEntry {
    char *key;
    int cnt;
    char *(returnStr[MAXSIZE]);
    UT_hash_handle hh;
};

struct HashEntry *g_this = NULL;

char *ReturnChangeStr(char *inputStr)
{
    int lenInputStr = strlen(inputStr);
    int len = (int)(inputStr[0] - 'a');
    int i;
    char *returnStr = (char *)malloc((lenInputStr + 1) * sizeof(char));

    for (i = 0; i < lenInputStr; i++) {
        if ((inputStr[i] - len) >= 'a' && (inputStr[i] - len) <= 'z') {
            returnStr[i] =  inputStr[i] - len;   
        } else {
            returnStr[i] = inputStr[i]  + ALPHASIZE - len;
        }
    }

    returnStr[lenInputStr] = '\0';
    return returnStr;
}

char ***GetStrFromHashEntry(int differCount, int** returnColumnSizes)
{
    int i;
    struct HashEntry *current;
    struct HashEntry *tmp;
    int returnIndex = 0;
    char ***return3Str = (char ***)malloc(differCount * sizeof(char **));

    HASH_ITER(hh, g_this, current, tmp) {
        (*returnColumnSizes)[returnIndex] = current->cnt;
        return3Str[returnIndex] = (char **)malloc((current->cnt) * sizeof(char *));
        for (i = 0; i < current->cnt; i++) {
            return3Str[returnIndex][i] = (char *)malloc((strlen(current->key) + 1) * sizeof(char));
            memcpy(return3Str[returnIndex][i], current->returnStr[i], (strlen(current->key) + 1) * sizeof(char));
        }
        returnIndex++;
        HASH_DEL(g_this, current);
        free(current);
    }

    return return3Str;
}

char *** groupStrings(char ** strings, int stringsSize, int* returnSize, int** returnColumnSizes)
{
    if ((strings == NULL) || (stringsSize == 0)) {
        *returnSize = 0;
        (*returnColumnSizes)[0] = (int *)malloc(sizeof(int));
        (*returnColumnSizes)[0] = 0;
        return NULL;
    }
    int i;
    int differCount = 0;
    struct HashEntry *tmpHashEntry;
    char *changeStr;

    for (i = 0; i < stringsSize; i++) {
        char *key = (char *)malloc((strlen(strings[i]) + 1) * sizeof(char));
        changeStr = ReturnChangeStr(strings[i]);
        memcpy(key, changeStr, (strlen(changeStr) + 1) * sizeof(char));
        HASH_FIND_STR(g_this, key, tmpHashEntry);
        if (tmpHashEntry == NULL) {
            tmpHashEntry = (struct HashEntry *)malloc(sizeof(struct HashEntry));
            tmpHashEntry->key = key;
            tmpHashEntry->cnt = 0;
            tmpHashEntry->returnStr[tmpHashEntry->cnt] = (char *)malloc((strlen(tmpHashEntry->key) + 1) * sizeof(char));
            memcpy(tmpHashEntry->returnStr[tmpHashEntry->cnt], strings[i],
                (strlen(tmpHashEntry->key) + 1) * sizeof(char));
            tmpHashEntry->cnt++;
            HASH_ADD_KEYPTR(hh, g_this, tmpHashEntry->key, strlen(tmpHashEntry->key), tmpHashEntry);
            differCount++;
        } else {
            tmpHashEntry->returnStr[tmpHashEntry->cnt] = (char *)malloc((strlen(tmpHashEntry->key) + 1) * sizeof(char));
            memcpy(tmpHashEntry->returnStr[tmpHashEntry->cnt], strings[i],
                (strlen(tmpHashEntry->key) + 1) * sizeof(char));
            tmpHashEntry->cnt++;
        }
    }

    char ***return3Str;
    *returnSize = differCount;
    (*returnColumnSizes) = (int *)malloc(differCount * sizeof(int));

    return3Str = GetStrFromHashEntry(differCount, returnColumnSizes);

    return return3Str;
}
```
