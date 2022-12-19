### 解题思路
此处撰写解题思路

### 代码

```c
struct HashEntry {
    char *key;
    int val;
    int cnt;
    UT_hash_handle hh;
};

struct HashEntry *g_this = NULL;

void FreeHash()
{
    struct HashEntry *node = NULL;
    struct HashEntry *tmp = NULL;
    HASH_ITER(hh, g_this, node, tmp)
    {
        free(node->key);
        HASH_DEL(g_this, node);
        free(node);
    }
}

bool ResetHashEntry()
{
    struct HashEntry *node = NULL;
    struct HashEntry *tmp = NULL;
    bool returnVal = true;
    HASH_ITER(hh, g_this, node, tmp)
    {
        if (node->val != node->cnt) {
            returnVal = false;
        }
        node->cnt = 0;
    }
    return returnVal;
}

void AddToHash(char **words, int wordsSize)
{
    int len = (strlen(words[0]) + 1);
    struct HashEntry *node = NULL;
    for (int i = 0; i < wordsSize; i++) {
        char *strKey = (char *)malloc(len * sizeof(char));
        memcpy(strKey, words[i], len * sizeof(char));
        HASH_FIND_STR(g_this, strKey, node);
        if (node == NULL) {
            node = (struct HashEntry *)malloc(sizeof(struct HashEntry));
            node->key = strKey;
            node->val = 1;
            node->cnt = 0;
            HASH_ADD_KEYPTR(hh, g_this, node->key, strlen(node->key), node);
        } else {
            node->val++;
        }
    }
}

int *GetRes(char *s, char **words, int wordsSize, int *returnSize)
{
    int eachLen = strlen(words[0]);
    int totalLen = eachLen * wordsSize;
    int *returnArray = (int *)malloc(256 * sizeof(int));
    if (returnArray == NULL) {
        return NULL;
    }
    memset(returnArray, 0, 256 * sizeof(int));

    char *tmpStr = (char *)malloc((eachLen + 1) * sizeof(char));
    struct HashEntry *node;
    for (int i = 0; i <= strlen(s) - totalLen; i++) {
        for (int j = i; j < i + totalLen; j++) {
            memcpy(tmpStr, &s[j], eachLen * sizeof(char));
            tmpStr[eachLen] = '\0';
            HASH_FIND_STR(g_this, tmpStr, node);
            if (node != NULL) {
                node->cnt++;
            }
            j = j + eachLen - 1;
        }
        if (ResetHashEntry()) {
            returnArray[*returnSize] = i;
            (*returnSize)++;
        }
    }
    return returnArray;
}
/* *
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
    *returnSize = 0;
    if ((s == NULL) || (words == NULL) || (wordsSize == 0)) {
        return NULL;
    }

    if (strlen(s) < strlen(words[0]) * wordsSize) {
        FreeHash();
        return NULL;
    }

    AddToHash(words, wordsSize);
    int *returnArray = NULL;
    returnArray = GetRes(s, words, wordsSize, returnSize);
    if (returnArray == NULL) {
        *returnSize = 0;
        return NULL;
    }
    FreeHash();
    return returnArray;
}
```