### 解题思路
    该颜色的兔子数量减一作为key，相同回答出现的次数作为value，出现次数超过该颜色兔子的可能数量则说明有另一种颜色的兔子和该颜色的数量相同。不详细写了，细细想一下。

### 代码

```c
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} entry;

void DeleteHash(entry** hashTable)
{
    entry* curEntry, *tmpEntry;
    HASH_ITER(hh, *hashTable, curEntry, tmpEntry) {
        HASH_DEL(*hashTable, curEntry);
        free(curEntry);
    }
    free(*hashTable);
    return;
}

int numRabbits(int* answers, int answersSize){
    if (!answers || answersSize <= 0) {
        return 0;
    }
    int cnt = 0;

    entry* hashTable = NULL;
    entry* findK;
    int k;
    for (int i = 0; i < answersSize; i++) {
        findK = NULL;
        k = answers[i];
        HASH_FIND_INT(hashTable, &k, findK);
        if (!findK) {
            cnt += (k + 1);
            entry* e = (entry*)malloc(sizeof(entry));
            e->key = k;
            e->val = 1;
            HASH_ADD_INT(hashTable, key, e);
        } else {
            (findK->val)++;
            int num = findK->key + 1;
            if (findK->val > num) {
                cnt += num;
                findK->val = 1;
            }
        }
    }
    DeleteHash(&hashTable);
    return cnt;
}
```