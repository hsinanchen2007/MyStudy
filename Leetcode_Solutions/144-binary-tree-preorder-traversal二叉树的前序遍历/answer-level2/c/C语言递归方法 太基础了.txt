
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
void pre_order_traversal(struct TreeNode* root, int* returnNums,int* returnSize)
{
    if(root!=NULL)
    {
        returnNums[*returnSize] = root->val;
        *returnSize = *returnSize + 1;
        pre_order_traversal(root->left,returnNums,returnSize);
        pre_order_traversal(root->right,returnNums,returnSize);
    }
}


int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* returnNums = (int*)malloc(sizeof(int)*1000);
    *returnSize = 0;
    pre_order_traversal(root,returnNums,returnSize);
    return returnNums;
}
```