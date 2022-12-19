
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
void post_order_traversal(struct TreeNode* root,int* returnNums,int* returnSize)
{
    if(root!=NULL)
    {
        post_order_traversal(root->left,returnNums,returnSize);
        post_order_traversal(root->right,returnNums,returnSize);
        returnNums[*returnSize] = root->val;
        *returnSize = *returnSize +1;
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* returnNums = (int*)malloc(sizeof(int)*1000);
    *returnSize = 0;
    if(root == NULL)
    {
        return returnNums;
    }
    post_order_traversal(root,returnNums,returnSize);
    return returnNums;
}
```