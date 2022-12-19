![FABE3F4E-4144-4668-9721-468EDB7F4D31.jpeg](https://pic.leetcode-cn.com/e75b82dcc206e164add0429e6c44c80cef4dec4f84086f809df871fbf0f71d30-FABE3F4E-4144-4668-9721-468EDB7F4D31.jpeg)

```
struct HashEntry {
    int key;
    int val;
    UT_hash_handle hh;
};

struct HashEntry *g_this = NULL;

int findLucky(int* arr, int arrSize)
{
    if ((arr == NULL) || (arrSize == 0)) {
        return 0;
    }
    struct HashEntry *tmpHashEntry;
    int i;
    int key;
    for (i = 0; i < arrSize; i++) {
        key = arr[i];
        HASH_FIND_INT(g_this, &key, tmpHashEntry);
        if (tmpHashEntry == NULL) {
            tmpHashEntry = (struct HashEntry *)malloc(sizeof(struct HashEntry));
            tmpHashEntry->key = key;
            tmpHashEntry->val = 0;
            tmpHashEntry->val++;
            HASH_ADD_INT(g_this, key, tmpHashEntry);
        } else {
            tmpHashEntry->val++;
        }
    }
    int returnMaxVal = -1;
    struct HashEntry *current;
    struct HashEntry *tmp;
    HASH_ITER(hh, g_this, current, tmp) {
        if ((current->key == current->val) && (returnMaxVal < current->key)) {
            returnMaxVal = current->key;
        }
        HASH_DEL(g_this, current);
        free(current);
    }
    
    return returnMaxVal;
}
```
