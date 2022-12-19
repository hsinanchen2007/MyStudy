### 解题思路
经典的hash表问题，C语言使用uthash解决。

1.将数据建立hash表

2.遍历hash表，对于每个key，按照其个数循环，判断是否能够组成正确结果。

注意，遍历的时候，先要减掉当前值的计数，再判断另一个值是否满足。


![image.png](https://pic.leetcode-cn.com/f4028faae00ba2c88b47a8b2a3bb15ab9600ae25eb43d813bffbf37d8033eb34-image.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define RET_LEN     100000

typedef struct _hash_st {
    int key;
    int val;
    UT_hash_handle hh;
}hash_st;

int ret_[RET_LEN][2];

//【算法思路】hash表。注意遍历的时候先减掉自身。
int** pairSums(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    hash_st *pool = (hash_st *)calloc(numsSize, sizeof(hash_st));
    int psize = 0;

    hash_st *head = NULL;

    //遍历记录hash表
    for(int i = 0; i < numsSize; i++) {
        hash_st *new = &pool[psize];
        new->key = nums[i];
        new->val = 1;

        hash_st *tmph;
        HASH_FIND_INT(head, &(new->key), tmph);

        if(tmph == NULL) {
            HASH_ADD_INT(head, key, new);
            psize++;

            continue;
        }

        tmph->val++;
    }

    hash_st *cur, *tmph;
    int rsize = 0;
    HASH_ITER(hh, head, cur, tmph) {
        while(cur->val > 0) {
            cur->val--;

            int a = cur->key;
            int b = target - a;

            hash_st *tmp;
            HASH_FIND_INT(head, &b, tmp);

            if(tmp == NULL || tmp->val == 0) {
                break;
            }

            tmp->val--;

            ret_[rsize][0] = a;
            ret_[rsize][1] = b;
            rsize++;
        }
    }

    int **ret = (int **)calloc(rsize, sizeof(int*));
    int *ret_col = (int *)calloc(rsize, sizeof(int));

    for(int i = 0; i < rsize; i++) {
        ret[i] = ret_[i];
        ret_col[i] = 2;
    }

    *returnSize = rsize;
    *returnColumnSizes = ret_col;
    return ret;
}
```