### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int key;
    UT_hash_handle hh;
} entry;

int MaxNum(int a, int b)
{
    return a > b ? a : b;
}

void DeleteHashSet(entry** hashSet)
{
    entry* curEntry, *tmpEntry;
    HASH_ITER(hh, *hashSet, curEntry, tmpEntry) {
        HASH_DEL(*hashSet, curEntry);
        free(curEntry);
    }
    return;
}

int lengthOfLongestSubstring(char * s){
    if (!s) {
        return 0;
    }
    entry* hashSet = NULL;
    int left = 0;
    int right = 0;
    entry* findK;
    int k;
    int res = 0;
    while (s[right] != '\0') {
        findK = NULL;
        k = s[right];
        HASH_FIND_INT(hashSet, &k, findK);
        if (findK) {
            res = MaxNum(res, right - left);
            findK = NULL;
            k = s[left];
            HASH_FIND_INT(hashSet, &k, findK);
            if (findK) {
                HASH_DEL(hashSet, findK);
                free(findK);
            }
            left++;
        } else {
            entry* e = (entry*)malloc(sizeof(entry));
            e->key = s[right];
            HASH_ADD_INT(hashSet, key, e);
            right++;
        }
    }
    res = MaxNum(res, right - left);
    DeleteHashSet(&hashSet);
    return res;
}
```