### 解题思路
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]



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


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int *col;
int k;
int **g_res;

void dfs(struct TreeNode* root, int sum, int *res, int reslen) {
    if (root == NULL)
        return;
    int temp[1024], i;

    if (!root->left && !root->right && root->val == sum){
        g_res[k] = malloc((reslen + 1) * sizeof(int));
        memcpy(g_res[k], res, reslen * sizeof(int));
        g_res[k][reslen] = root->val;
        col[k] = reslen + 1;
        k++;
    }
    
    memcpy(temp, res, reslen * sizeof(int));
    temp[reslen] = root->val;
    dfs(root->left, sum - root->val, temp, reslen + 1);
    dfs(root->right, sum - root->val, temp, reslen + 1);
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    int res, i;
    g_res = malloc(1000 * sizeof(int *));
    memset(g_res, 0, 1000 * sizeof(int *));

    col = malloc(1000 * sizeof(int));
    memset(col, 0, 1000 * sizeof(int));
    k = 0;
    dfs(root, sum, &res, 0);
    
    *returnSize = k;
    *returnColumnSizes = malloc(k * sizeof(int));
    for (i = 0; i < k; i++)
        (*returnColumnSizes)[i] = col[i];
    return g_res;
}
```