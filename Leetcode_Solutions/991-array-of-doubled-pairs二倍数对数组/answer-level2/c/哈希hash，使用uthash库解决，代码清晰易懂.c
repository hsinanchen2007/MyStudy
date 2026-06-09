### 解题思路
![image.png](https://pic.leetcode-cn.com/66d899a9caa16ca3c5246010509586007687ed580cf4a4204506db153c8db3a8-image.png)

### 代码

```c
#include <uthash.h>
struct Number {
    int key;
    int cnt;
    UT_hash_handle hh;
};

static void Release(struct Number **hash)
{
    struct Number *node, *next;
    HASH_ITER(hh, *hash, node, next) {
        HASH_DEL(*hash, node);
    }
}

static int Cmp(struct Number *a, struct Number *b)
{
    return a->key - b->key;
}

static void CountNum(struct Number **hash, int num, int cnt)
{
    struct Number *node = NULL;
    HASH_FIND_INT(*hash, &num, node);
    if (node != NULL) {
        node->cnt++;
        return;
    }
    node = malloc(sizeof(struct Number));
    node->cnt = cnt;
    node->key = num;
    HASH_ADD_INT(*hash, key, node);
}

static void CountArray(struct Number **hash, int *array, int n)
{
    for (int i = 0; i < n; i++) {
        CountNum(hash, array[i], 1);
    }
}

bool canReorderDoubled(int *nums, int numsSize)
{
    struct Number *ha = NULL;
    CountArray(&ha, nums, numsSize);
    HASH_SORT(ha, Cmp);

    struct Number *node = NULL;
    struct Number *next = NULL;
    HASH_ITER(hh, ha, node, next) {
        struct Number *tmp = NULL;
        int tmpNum = 0;
        while (node->cnt > 0) {
            if (node->key < 0) {
                tmpNum = node->key / 2;
                HASH_FIND_INT(ha, &tmpNum, tmp);
                if (tmp == NULL) {
                    return false;
                }
            } else {
                tmpNum = node->key * 2;
                HASH_FIND_INT(ha, &tmpNum, tmp);
                if (tmp == NULL) {
                    return false;
                }
            }
            if (tmp->cnt > 0) {
                tmp->cnt--;
            } else {
                return false;
            }
            node->cnt--;
        }        
    }
    Release(&ha);
    return true;
}
```