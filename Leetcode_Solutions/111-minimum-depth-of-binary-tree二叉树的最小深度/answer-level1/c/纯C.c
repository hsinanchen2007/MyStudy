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


int minDepth(struct TreeNode* root){
    if (NULL == root)
    {
        return 0;
    }

    if (NULL == root->left)
    {
        return minDepth(root->right) + 1;
    }

    if (NULL == root->right)
    {
        return minDepth(root->left) + 1;
    }

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    return (left < right ? left : right) + 1;
}
```