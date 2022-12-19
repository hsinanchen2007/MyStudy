![9834F200-4D7D-4560-9E57-42F58B9C497E.jpeg](https://pic.leetcode-cn.com/b90eefb91f61a0ee326ceca6f0c0d85a4abc835378cdb70ff5f8af092114ca94-9834F200-4D7D-4560-9E57-42F58B9C497E.jpeg)

```
#define SUBSTRSIZE 11

struct HashEntry {
    char *key;
    int cnt;
    UT_hash_handle hh;
};

struct HashEntry *g_this = NULL;
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findRepeatedDnaSequences(char * s, int* returnSize)
{
    if ((s == NULL) || (strlen(s) == 0)) {
        *returnSize = 0;
        return NULL;
    }
    if (strlen(s) < SUBSTRSIZE - 1) {
        *returnSize = 0;
        return NULL;
    }
    struct HashEntry *tmpHashEntry;
    int i;
    int returnStrColSize = 0;
    char *subStr;
    *returnSize = 0;
    for (i = 0; i <= strlen(s) - SUBSTRSIZE + 1; i++) {
        subStr = (char *)malloc(SUBSTRSIZE * sizeof(char));
        memcpy(subStr, &s[i], (SUBSTRSIZE - 1) * sizeof(char));
        subStr[SUBSTRSIZE - 1] = '\0';
        HASH_FIND_STR(g_this, subStr, tmpHashEntry);
        if (tmpHashEntry == NULL) {
            tmpHashEntry = (struct HashEntry *)malloc(sizeof(struct HashEntry));
            tmpHashEntry->key = subStr;
            tmpHashEntry->cnt = 0;
            tmpHashEntry->cnt = 1;
            HASH_ADD_KEYPTR(hh, g_this, tmpHashEntry->key, strlen(tmpHashEntry->key), tmpHashEntry);
        } else {
            tmpHashEntry->cnt++;
            returnStrColSize++;
        }
        //printf("subStr: %s, cnt: %d\n", tmpHashEntry->key, tmpHashEntry->cnt);
    }
    char **returnStr = (char **)malloc(returnStrColSize * sizeof(char *));
    struct HashEntry *current;
    struct HashEntry *tmp;
    HASH_ITER(hh, g_this, current, tmp) {
        if (current->cnt > 1) {
            returnStr[*returnSize] = (char *)malloc(SUBSTRSIZE * sizeof(char));
            memcpy(returnStr[*returnSize], current->key, SUBSTRSIZE * sizeof(char));
            (*returnSize)++;
        }
        HASH_DEL(g_this, current);
        free(current);
    }

    return returnStr;
}
```
