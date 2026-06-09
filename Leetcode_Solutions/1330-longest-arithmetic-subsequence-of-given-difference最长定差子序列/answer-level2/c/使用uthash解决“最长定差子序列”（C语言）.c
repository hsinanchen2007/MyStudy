### 解题思路
本题直观的思路是使用hash表解决查找前一个定差值。

对于C语言来说，主要使用uthash库函数解决问题。

但是本题的c实现难点在于，**直接将arr[i]的值作为key，使用uthash解决本题时，出现了hash冲突。**

一种解决办法时将arr[i]*大素数，来解决hash冲突问题。

### 代码

```c
/*
 * @lc app=leetcode.cn id=1218 lang=c
 *
 * [1218] 最长定差子序列
 */

// @lc code=start
#define MMAX(a, b)      ((a) > (b)? (a) : (b))
#define POOL_SIZE   50000

#define HASH_BASE 1331

typedef struct _hash_st
{
    int key;
    int val;
    UT_hash_handle hh;
}hash_st;


//【算法思路】hash。记录每个元素的最长等差序列，新增一个元素时，使用hash加速遍历之前的序列，取最长更新到自身。

int longestSubsequence(int* arr, int arrSize, int difference){
    hash_st *pool = (hash_st *)calloc(POOL_SIZE, sizeof(hash_st));
    int psize = 0;

    hash_st *head = NULL;

    int max = 0;
    for(int i = 0; i < arrSize; i++)
    {
        //准备加入的时当前值的key
        hash_st *cur = &pool[psize];
        cur->key = arr[i] * HASH_BASE;
        cur->val = 1;

        int pre = (arr[i] - difference) * HASH_BASE;

        //需要查找的时
        //首先找到是否存在上一级数值
        hash_st *tmph;
        HASH_FIND_INT(head, &pre, tmph);

        //如果不存在上一级，则直接加入当前值节点
        if(tmph == NULL)
        {
            HASH_ADD_INT(head, key, cur);
            psize++;

            max = MMAX(max, 1);
            continue;
        }

        //如果存在当前上一级节点，获得最大值
        int tmax = tmph->val + 1;

        //判断是否存在当前值的节点
        HASH_FIND_INT(head, &cur->key, tmph);

        if(tmph == NULL)
        {
            cur->val = tmax;

            HASH_ADD_INT(head, key, cur);
            psize++;

            max = MMAX(max, tmax);
            continue;
        }

        tmph->val = MMAX(tmph->val, tmax);

        max = MMAX(max, tmph->val);
    }
/*
    hash_st *cur_, *tmph_;
    HASH_ITER(hh, head, cur_, tmph_)
    {
        printf("[%d, %d]  ", cur_->key, cur_->val);
    }
    printf("\n");
*/
    return max;
}


// @lc code=end


```