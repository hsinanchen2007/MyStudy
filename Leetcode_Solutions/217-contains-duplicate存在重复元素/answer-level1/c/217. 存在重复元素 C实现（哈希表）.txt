### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int key;
    UT_hash_handle hh;
} entry;

void DeleteHash(entry** set)
{
    entry *cur, *tmp;
    HASH_ITER(hh, *set, cur, tmp) {
        HASH_DEL(*set, cur);
        free(cur);
    }
    return;
}

bool containsDuplicate(int* nums, int numsSize){
    if (!nums || numsSize <= 0) {
        return false;
    }
    entry* set = NULL;
    int key;
    entry* findK;
    for (int i = 0; i < numsSize; i++) {
        findK = NULL;
        key = nums[i];
        HASH_FIND_INT(set, &key, findK);
        if (!findK) {
            entry* e = (entry*)malloc(sizeof(entry));
            e->key = key;
            HASH_ADD_INT(set, key, e);
        } else {
            DeleteHash(&set);
            return true;
        }
    }
    DeleteHash(&set);
    return false;
}
```