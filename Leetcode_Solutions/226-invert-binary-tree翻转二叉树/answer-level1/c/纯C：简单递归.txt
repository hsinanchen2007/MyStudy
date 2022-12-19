### 解题思路
思路：1.先交换节点的左右子树
      2.对左右子树分别递归

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
    if(root==NULL) return root;
    struct TreeNode *tmp=root;
    tmp=root->left;
    root->left=root->right;
    root->right=tmp;
    root->left=invertTree(root->left);
    root->right=invertTree(root->right);
    return root;
}
```