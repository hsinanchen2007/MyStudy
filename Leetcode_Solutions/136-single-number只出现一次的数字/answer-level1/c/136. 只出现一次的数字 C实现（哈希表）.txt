### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} entry;

void DeleteHash(entry** hashSet, int* res)
{
    entry* curEntry, *tmpEntry;
    HASH_ITER(hh, *hashSet, curEntry, tmpEntry) {
        if (curEntry->val == 1) {
            *res = curEntry->key;
        }
        HASH_DEL(*hashSet, curEntry);
        free(curEntry);
    }
    return;
}

int singleNumber(int* nums, int numsSize){
    entry* hashSet = NULL;
    entry* findK;
    int key, res;
    for (int i = 0; i < numsSize; i++) {
        findK = NULL;
        key = nums[i];
        HASH_FIND_INT(hashSet, &key, findK);
        if (findK) {
            findK->val++;
        } else {
            entry* e = (entry*)malloc(sizeof(entry));
            e->key = key;
            e->val = 1;
            HASH_ADD_INT(hashSet, key, e);
        }
    }
    DeleteHash(&hashSet, &res);
    return res;
}
```