### 解题思路
使用指针和工具函数减少全局变量的使用
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

int doDiameterOfBinaryTree(struct TreeNode* root,int* ans){
    if(!root) return 0;
    int L=doDiameterOfBinaryTree(root->left,ans);
    int R=doDiameterOfBinaryTree(root->right,ans);
    *ans = (*ans<L+R+1)?(R+L+1):*ans;
    return (L>R?L:R)+1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    int maxD = 1;
    doDiameterOfBinaryTree(root,&maxD);
    return maxD-1;
}
```