
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

void intravel(struct TreeNode* root,int* a,int* returnSize)
{
    if(root!=NULL)
    {
        intravel(root->left,a,returnSize);
        a[*returnSize] = root->val;
        *returnSize = *returnSize +1;
        intravel(root->right,a,returnSize);
    }
}



int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int* a = (int*)malloc(sizeof(int)*500);
    intravel(root,a,returnSize);
    return a;
}
```