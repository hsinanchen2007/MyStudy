### 解题思路
纯C

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


int maxDepth(struct TreeNode* root){
    if (NULL == root)
    {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    
    return (left > right ? left : right) + 1;
}
```