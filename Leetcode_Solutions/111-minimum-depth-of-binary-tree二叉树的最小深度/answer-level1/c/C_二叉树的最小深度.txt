### 解题思路
测量二叉树深度的递归函数中返回的是较大的子树深度+1，此题返回较小的即可

注意：若一个子树为空，返回另一个子树的最小深度+1

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
    if(root==0)
        return 0;
    else
    {
        int leftHeight=minDepth(root->left);
        int rightHeight=minDepth(root->right);
        if(root->left==0)return rightHeight+1;
        if(root->right==0)return leftHeight+1;
        return leftHeight<rightHeight?leftHeight+1:rightHeight+1;
    }
}
```