### 解题思路
如题，递归，找每个子树的最小深度。需要注意的是叶子节点的定义，是没有子节点的节点，换句话就是，如果一个节点只有左子节点，这时应该计算这个节点左边子树的深度，而不是返回右边子树的0。

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
    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL)return 1;
    if(root->left==NULL)return (minDepth(root->right)+1);
    if(root->right==NULL)return (minDepth(root->left)+1);
    int n_left=minDepth(root->left)+1;
    int n_right=minDepth(root->right)+1;
    return (n_left<n_right?n_left:n_right);
}
```