### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} entry;

entry* GetEntry(entry** hashTable, int key)
{
    entry* findK = NULL;
    HASH_FIND_INT(*hashTable, &key, findK);
    return findK;
}

void PutEntry(entry** hashTable, int key, int val)
{
    entry* insert = (entry*)malloc(sizeof(entry));
    insert->key = key;
    insert->val = val;
    HASH_ADD_INT(*hashTable, key, insert);
}

void DeleteHashTable(entry** hashTable)
{
    entry* curEntry, *tmpEntry;
    HASH_ITER(hh, *hashTable, curEntry, tmpEntry){
        HASH_DEL(*hashTable, curEntry);
        free(curEntry);
    }
}

int numJewelsInStones(char * J, char * S){
    if (!J || !S) {
        return 0;
    }
    entry* hashTable = NULL;
    int idx = 0;
    while (J[idx] != '\0') {
        PutEntry(&hashTable, J[idx], J[idx]);
        idx++;
    }
    int cnt = 0;
    idx = 0;
    while (S[idx] != '\0') {
        if (GetEntry(&hashTable, S[idx])) {
            cnt++;
        }
        idx++;
    }
    DeleteHashTable(&hashTable);
    return cnt;
}
```