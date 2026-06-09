### 解题思路
此处撰写解题思路

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
 * Note: The returned array must be malloced, assume caller calls free().
 */

void middletrave(struct TreeNode *node, int *result, int *returnSize)
{
    if(node == NULL)
        return;
    
    middletrave(node->left, result, returnSize);
    result[*returnSize] = node->val;
    *returnSize = *returnSize + 1;
    middletrave(node->right, result, returnSize);
}

void treeSize(struct TreeNode *node, int *size)
{
    if(node == NULL)
        return;

   
   *size = *size + 1;
    treeSize(node->left, size);
    treeSize(node->right, size);
}


int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int size = 0;
    int *result = NULL;
    treeSize(root, &size);
    result = (int *)malloc(size*sizeof(int));

    *returnSize = 0;

    middletrave(root, result, returnSize);

    return result;
}
```