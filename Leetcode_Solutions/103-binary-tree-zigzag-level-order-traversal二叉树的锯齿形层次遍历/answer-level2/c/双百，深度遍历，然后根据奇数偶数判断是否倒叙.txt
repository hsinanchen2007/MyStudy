### 解题思路
深度遍历，然后根据奇数偶数判断是否倒叙，参考了102题的解题思路。
![20200312-214545(eSpace).png](https://pic.leetcode-cn.com/c94f991696e3aced181af0dff24485dd8781e1e7793377ef5499fa0dd69814fb-20200312-214545\(eSpace\).png)

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

int maxDepth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    int left_num = maxDepth(root->left) + 1;
    int right_num = maxDepth(root->right) + 1;
    return (left_num > right_num ? left_num : right_num);
}

void swap(struct TreeNode* root, int **res, int *ColumnSizes, int index) 
{
    if (ColumnSizes[index] == 0 ) {
        res[index][ColumnSizes[index]] = root->val;
        return ;
    }
    for (int i = ColumnSizes[index]; i > 0; i--) {
        res[index][i] = res[index][i- 1];
        
    }
    res[index][0] = root->val;
    return;
}

void helper(struct TreeNode* root, int **res, int *ColumnSizes, int index, int *maxth)
{
    if (root == NULL) {
        return;
    }

    if (index % 2 == 0) {
        res[index][ColumnSizes[index]] = root->val;
    } else {
        swap(root, res, ColumnSizes, index);
    }
    ColumnSizes[index]++;
    if (index + 1 > *maxth) {
        *maxth = index + 1;
    }

    helper(root->left, res, ColumnSizes, index + 1, maxth);
    helper(root->right, res, ColumnSizes, index + 1, maxth);  
    
    return;
}
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth = maxDepth(root);
    int **res = (int **)malloc(sizeof(int *) * depth);
    for (int i = 0; i < depth; i++) {
        res[i] = (int *)malloc(sizeof(int) * 1000);
        memset(res[i], 0, sizeof(int) * 1000);
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    memset(*returnColumnSizes, 0, sizeof(int) * 1000);
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    helper(root, res, *returnColumnSizes, 0, returnSize);

    return res;
}


```