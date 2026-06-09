### 解题思路
其实就是将左右子树进行交换，交换的话我们会需要第三个变量，这样就有了 p 
最后递归调用左右子树，树用的最多的就是递归。
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
    if(root == NULL) return NULL;
    struct TreeNode *p = root->left;
    root->left = root->right;
    root->right = p;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
```