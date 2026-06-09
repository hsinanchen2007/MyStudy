### 解题思路
纯C 没用非递归

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

#define PARAM_IN
#define PARAM_OUT
#define MAX_SIZE 6000

static void traverse(PARAM_IN struct TreeNode* psRoot, PARAM_OUT int* pRes, PARAM_OUT int* returnSize)
{
    if (psRoot->left)
    {
        traverse(psRoot->left, pRes, returnSize);
    }

    pRes[*returnSize] = psRoot->val;
    (*returnSize)++;

    if (psRoot->right)
    {
        traverse(psRoot->right, pRes, returnSize);
    }
}

int* inorderTraversal(PARAM_IN struct TreeNode* root, PARAM_OUT int* returnSize){
    *returnSize = 0;
    
    if (NULL == root)
    {
        return NULL;
    }

    int* pRes = (int*)malloc(MAX_SIZE * sizeof(int));

    traverse(root, pRes, returnSize);

    return pRes;

}
```