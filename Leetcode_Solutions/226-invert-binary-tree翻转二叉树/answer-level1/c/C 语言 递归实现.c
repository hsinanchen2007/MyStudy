
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


struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL)
    {
        return root;
    }
    struct TreeNode* p;
    p = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = p;
    return root;
}
```