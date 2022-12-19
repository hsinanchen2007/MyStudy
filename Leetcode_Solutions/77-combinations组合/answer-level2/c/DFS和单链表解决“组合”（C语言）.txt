### 解题思路
典型的递归(返回所有可能结果)的问题。

下面给出不提前申请大数组的C语言标准解法，即单链表动态添加结果的方法。

1.构造单链表节点，用于存储动态长度的结果数组

2.根据构造递归函数，返回结果

3.根据结果构造data存储本级结果，并使用单链表链接

4.处理单链表结果，重新组合为数组指针的结构并返回

### 代码

```c
/*
 * @lc app=leetcode.cn id=77 lang=c
 *
 * [77] 组合
 */

// @lc code=start

typedef struct _info_st
{
    int *data;
    struct _info_st *nxt;
}info_st;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// 辅助函数功能为从长度为n的nums数组，选择自sid开始的k个数的所有组合
int **helper(int *nums, int n, int sid, int k, int *returnSize, int **returnColumnSizes)
{
    //printf("sid = %d, k = %d\n", sid, k);
    // 处理递归结尾
    if(k == 0)
    {
        int **res = (int **)calloc(1, sizeof(int *));
        res[0] = NULL;

        int *rcol_size = (int *)calloc(1, sizeof(int));
        rcol_size[0] = 0;

        *returnSize = 1;
        *returnColumnSizes = rcol_size;
        return res;
    }

    int rsize = 0;
    info_st *head = NULL;

    for(int i = sid; i < n - k + 1; i++)
    {
        int ret_size;
        int *ret_col_size;
        int **ret_res;

        // 选择i后，剩下的元素进行选取
        ret_res = helper(nums, n, i + 1, k - 1, &ret_size, &ret_col_size);

        //结果串入链表
        int col = k - 1;

        for(int j = 0; j < ret_size; j++)
        {
            int *data = (int *)calloc(col + 1, sizeof(int));

            data[0] = nums[i];

            for(int m = 0; m < col; m++)
            {
                data[m + 1] = ret_res[j][m];
            }

            info_st *cur = (info_st *)calloc(1, sizeof(info_st));
            cur->data = data;

            cur->nxt = head;
            head = cur;
/*
            for(int m = 0; m < col + 1; m++)
            {
                printf("%d ", cur->data[m]);
            }
            printf("\n");
*/
        }

        rsize += ret_size;
    }

    //printf("rsize = %d, sid = %d, k = %d\n", rsize, sid, k);

    // 将结果整合
    int **res = (int **)calloc(rsize, sizeof(int *));
    int *rcol_size = (int *)calloc(rsize, sizeof(int));

    info_st *cur = head;
    int rid = 0;
    while(cur != NULL)
    {
        res[rid] = cur->data;
        rcol_size[rid] = k;
        rid++;

        cur = cur->nxt;
    }
/*
    for(int i = 0; i < rsize; i++)
    {
        for(int j = 0; j < k; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    printf("\n");
*/
    *returnSize = rsize;
    *returnColumnSizes = rcol_size;
    return res;
}

// 【算法思路】DFS+单链表。典型的递归调用，单链表用于存储结果
int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    if(k > n || k < 0 || n <= 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int *nums = (int *)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }
/*
    for(int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
*/
    int **res = helper(nums, n, 0, k, returnSize, returnColumnSizes);

    return res;
}


// @lc code=end


```