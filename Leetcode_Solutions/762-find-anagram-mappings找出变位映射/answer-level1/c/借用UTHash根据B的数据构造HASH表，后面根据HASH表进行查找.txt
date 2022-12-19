### 解题思路
思路很明确，借用UTHASH构造HASH表后，后面根据HASH表进行查找
### 代码

```c
#include <uthash.h>
typedef struct E {
    int key;
    int index;
    UT_hash_handle hh;
}E;
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* anagramMappings(int* A, int ASize, int* B, int BSize, int* returnSize){
    E *hash_entry = NULL;

    int i;
    int k;
    E *out;
    /* 根据数组B构造HASH表 */
    for (i = 0; i < BSize; i++) {
        k = B[i];
        HASH_FIND_INT(hash_entry, &k, out);

        if (out == NULL) {
            out = (E *)malloc(sizeof(E));
            out->key   = k;
            out->index = i;
            HASH_ADD_INT(hash_entry, key, out);
        }

        /* 查找到了说明是重复的元素不进行处理 */
    }

    int *ret = (int *)malloc(sizeof(int) * ASize);
    memset(ret, 0, sizeof(int) * ASize);

    for (i = 0; i < ASize; i++) {
        k = A[i];
        HASH_FIND_INT(hash_entry, &k, out);
        /* 肯定可以找到这里不再进行判断 */
        ret[i] = out->index;
    }

    *returnSize = ASize;
    return ret;
}
```