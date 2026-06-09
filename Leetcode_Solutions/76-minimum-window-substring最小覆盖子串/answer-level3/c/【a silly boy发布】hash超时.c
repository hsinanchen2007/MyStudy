```
#define MAXSIZE 50000

struct HashEntry {
    int key;
    int tCnt;
    int sCnt;
    UT_hash_handle hh;
};

struct HashEntry *g_this = NULL;

bool IsHasWholeHashEntry()
{
    struct HashEntry *current;
    struct HashEntry *tmp;
    HASH_ITER(hh, g_this, current, tmp) {
        if (current->sCnt < current->tCnt) {
            return false;
        }
    }
    return true;
}

void ResetHashEntrySCnt()
{
    struct HashEntry *current;
    struct HashEntry *tmp;
    HASH_ITER(hh, g_this, current, tmp) {
        current->sCnt = 0;
    }
}

void DeleteHashEntrySCnt()
{
    struct HashEntry *current;
    struct HashEntry *tmp;
    HASH_ITER(hh, g_this, current, tmp) {
        HASH_DEL(g_this, current);
        free(current);
    }
}

void AddHashEntry(int *key, struct HashEntry *tmpHashEntry)
{
    HASH_FIND_INT(g_this, key, tmpHashEntry);
    if (tmpHashEntry == NULL) {
        tmpHashEntry = (struct HashEntry *)malloc(sizeof(struct HashEntry));
        tmpHashEntry->key = *key;
        tmpHashEntry->tCnt = 0;
        tmpHashEntry->sCnt = 0;
        tmpHashEntry->tCnt++;
        HASH_ADD_INT(g_this, key, tmpHashEntry);
    } else {
        tmpHashEntry->tCnt++;
    }
}

char * minWindow(char * s, char * t)
{
    int lenT = strlen(t);
    int lenS = strlen(s);
    char *returnVal = (char *)malloc((lenS + 1) * sizeof(char));
    memset(returnVal, 0, (lenS + 1) * sizeof(char));
    if (s == NULL) {
        return returnVal;
    }
    if (lenS < lenT) {
        return returnVal;
    }
    int i;
    int key;
    struct HashEntry *tmpHashEntry;
    for (i = 0; i < lenT; i++) {
        key = (int)(t[i]);
        AddHashEntry(&key, tmpHashEntry);
    }
    int returnCnt = lenS + 1;
    int startIndex = 0;
    int secondIndex = 0;
    int endIndex = 0;
    bool isFirst = false;
    bool isSecond = false;

    struct HashEntry *sHashEntry;
    for (i = 0; i < lenS; i++) {
        key = (int)(s[i]);
        HASH_FIND_INT(g_this, &key, sHashEntry);
        if (sHashEntry != NULL) {
            if ((isFirst == true) && (isSecond == false)) {
                secondIndex = i;
                isSecond = true;
            }
            if (isFirst == false) {
                startIndex = i;
                isFirst = true;
            }
            sHashEntry->sCnt++;
            if (IsHasWholeHashEntry() == true) {
                endIndex = i;
                if ((endIndex - startIndex) < returnCnt) {
                    returnCnt = endIndex - startIndex;
                    memcpy(returnVal, &s[startIndex], ((endIndex - startIndex) + 1) * sizeof(char));
                    returnVal[endIndex - startIndex + 1] = '\0';
                }
                ResetHashEntrySCnt();
                if (isSecond == true) {
                    startIndex = secondIndex;
                    isFirst = false;
                    isSecond = false;
                    i = startIndex - 1;
                } else {
                    isFirst = false;
                    i = startIndex;
                }
            }
        }
    }
    DeleteHashEntrySCnt();
    return returnVal;
}
```
