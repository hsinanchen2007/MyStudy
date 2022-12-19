### 解题思路
刚从求数的最大深度过来，直接套用
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


bool isBalanced(struct TreeNode* root){
    int maxdepth(struct TreeNode *root);
    if(!root) return true;
    return isBalanced(root->left)&&isBalanced(root->right)&&abs(maxdepth(root->left)-maxdepth(root->right))<=1; //只需要在后面加上左右子树高度之差小于等于1
}
int maxdepth(struct TreeNode *root){
    if(!root) return 0;
    int l=maxdepth(root->left)+1;
    int r=maxdepth(root->right)+1;
    return l>r?l:r;
}
```