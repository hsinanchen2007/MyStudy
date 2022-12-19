### 解题思路
对于C语言，本题的难点在于数据的存储。

由于题目数据量不大，因此直接使用数组实现hash，注意记录结果值和层级。

最终输出需要排序，优先排序层级，层级相同排序val。

C语言在实现的时候，可以考虑单链表插入排序，但是编程复杂度较高，因此选择任意插入，处理结果时qsort的方案。

1.dfs遍历二叉树，将存有val和层级信息的数据，放入hash表

2.遍历hash表处理结果，注意使用qsort完成两重条件排序

3.构造结果数组，存储结果

![image.png](https://pic.leetcode-cn.com/66293649eb416fd92d993d249807dbb59979d7e6f3c4f47ebcee823b7b7fd467-image.png)


### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define NUM_SIZE        1000
#define ZERO_BASE       1000

typedef struct _info_st
{
    int lvl;
    int val;
}info_st;

info_st hash[ZERO_BASE * 2][NUM_SIZE];
int *hcol_size;

int res_[ZERO_BASE * 2][NUM_SIZE];
int *res[ZERO_BASE * 2];
int *rcol_size;

void helper(struct TreeNode* root, int x, int y)
{
    int hid = ZERO_BASE + x;

    hash[hid][ hcol_size[hid] ].lvl = y;
    hash[hid][ hcol_size[hid] ].val = root->val;
    hcol_size[hid]++;

    if(root->left != NULL)
    {
        helper(root->left, x - 1, y + 1);
    }

    if(root->right != NULL)
    {
        helper(root->right, x + 1, y + 1);
    }
}

int compare(const void *a, const void *b)
{
    if((*(info_st *)a).lvl == (*(info_st *)b).lvl)
    {
        return (*(info_st *)a).val - (*(info_st *)b).val;
    }
    else
    {
        return (*(info_st *)a).lvl - (*(info_st *)b).lvl;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** verticalTraversal(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    hcol_size = (int *)calloc(ZERO_BASE * 2, sizeof(int));
    rcol_size = (int *)calloc(ZERO_BASE * 2, sizeof(int));

    helper(root, 0, 0);

    //整理结果
    int rsize = 0;

    for(int i = 0; i < ZERO_BASE * 2; i++)
    {
        if(hcol_size[i] == 0)
        {
            continue;
        }

        //printf("col size[%d] = %d\n", i - ZERO_BASE, hcol_size[i]);

        qsort(hash[i], hcol_size[i], sizeof(info_st), compare);
/*
        for(int j = 0; j < hcol_size[i]; j++)
        {
            printf("%d  ", hash[i][j]);
        }
        printf("\n");
*/
        res[rsize] = res_[rsize];
        for(int j = 0; j < hcol_size[i]; j++)
        {
            res[rsize][j] = hash[i][j].val;
        }

        rcol_size[rsize] = hcol_size[i];
        rsize++;
    }

    *returnSize = rsize;
    *returnColumnSizes = rcol_size;
    return res;
}
```