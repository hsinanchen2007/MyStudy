### 解题思路
此处撰写解题思路
1、使用uthash数据结构，记录key和对应出现次数
2、然后根据cnt进行排序
3、输出排序后前K数据
### 代码

```c
#include <uthash.h>
struct Number {
    int key;
    int cnt;
    UT_hash_handle hh;
};

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

static void Release(struct Number **hash)
{
    struct Number *node, *next;
    HASH_ITER(hh, *hash, node, next) {
        HASH_DEL(*hash, node);
    }
}

static int Cmp(struct Number *a, struct Number *b)
{
    return b->cnt - a->cnt;
}

int *topKFrequent(int *nums, int numsSize, int k, int *returnSize)
{
    int *result = malloc(sizeof(int) * k);
    assert(result != NULL);
    *returnSize = k;
    struct Number *ha = NULL;
    CountArray(&ha, nums, numsSize);
    HASH_SORT(ha, Cmp);
    
    int index = 0;
    struct Number *node = NULL;
    struct Number *next = NULL;
    HASH_ITER(hh, ha, node, next) {
        result[index++] = node->key;
        if (index == k) {
            break;
        }
    }
    Release(&ha);
    return result;
}
```