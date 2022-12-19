![E74F575D-4ABE-493E-A4F1-138C78B80DBF.jpeg](https://pic.leetcode-cn.com/1aeb2022cc098aeb1495fd2245175f9f3bee31fe64c6098be00d84e49845840e-E74F575D-4ABE-493E-A4F1-138C78B80DBF.jpeg)

```
#define STRCOUNT 256

struct HashEntry {
    char *key;
    int val;
    int cnt;
    UT_hash_handle hh;
};

struct HashEntry *g_this = NULL;

void FreeHash() 
{
    struct HashEntry *currentHashEntry;
    struct HashEntry *tmp;
    HASH_ITER(hh, g_this, currentHashEntry, tmp) {
        HASH_DEL(g_this, currentHashEntry);
        free(currentHashEntry);
    }
}

bool ResetHashEntry()
{
    struct HashEntry *currentHashEntry;
    struct HashEntry *tmp;
    bool returnVal = true;
    HASH_ITER(hh, g_this, currentHashEntry, tmp) {
        if (currentHashEntry->val != currentHashEntry->cnt) {
            returnVal = false;
        }
        currentHashEntry->cnt = 0;
    }
    return returnVal;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    if ((s == NULL) || (words == NULL) || (wordsSize == 0)) {
        *returnSize = 0;
        return NULL;
    }
    int i;
    int j;
    int totalLen = 0;
    int eachLen = strlen(words[0]);
    struct HashEntry *tmpHashEntry;
    char *strKey;
    int differCount = 0;
    int minLenStr = 256;
    for (i = 0; i < wordsSize; i++) {
        strKey = (char *)malloc((strlen(words[i]) + 1) * sizeof(char));
        memcpy(strKey, words[i], (strlen(words[i]) + 1) * sizeof(char));
        if (minLenStr > strlen(words[i])) {
            minLenStr = strlen(words[i]);
        }
        HASH_FIND_STR(g_this, strKey, tmpHashEntry);
        if (tmpHashEntry == NULL) {
            tmpHashEntry = (struct HashEntry *)malloc(sizeof(struct HashEntry));
            tmpHashEntry->key = strKey;
            tmpHashEntry->val = 1;
            tmpHashEntry->cnt = 0;
            HASH_ADD_KEYPTR(hh, g_this, tmpHashEntry->key, strlen(tmpHashEntry->key), tmpHashEntry);
            differCount++;
        } else {
            tmpHashEntry->val++;
        }
        totalLen = totalLen + strlen(words[i]);
        //printf("key: %s, count: %d\n", tmpHashEntry->key, tmpHashEntry->val);
    }

    if (strlen(s) < totalLen) {
        FreeHash();
        *returnSize = 0;
        return NULL;
    }
    int *returnArray = (int *)malloc(256 * sizeof(int));
    memset(returnArray, 0, 256 * sizeof(int));
    
    char *tmpStr = (char *)malloc((eachLen + 1) * sizeof(char));
    struct HashEntry *tmpHashEntry2;
    bool isTrue = true;
    int returnVal = 0;
    *returnSize = 0;
    for (i = 0; i <= strlen(s) - totalLen; i++) {
        for (j = i; j < i + totalLen; j++) {
            memcpy(tmpStr, &s[j], eachLen * sizeof(char));
            tmpStr[eachLen] = '\0';
            HASH_FIND_STR(g_this, tmpStr, tmpHashEntry2);
            if (tmpHashEntry2 != NULL) {
                // 添加计数
                tmpHashEntry2->cnt++;
            }
            j = j + eachLen - 1;
        }
        isTrue = ResetHashEntry();
        if (isTrue == true) {
            returnArray[*returnSize] = i;
            (*returnSize)++;
        }
    }
    FreeHash();
    return returnArray;
}
```
