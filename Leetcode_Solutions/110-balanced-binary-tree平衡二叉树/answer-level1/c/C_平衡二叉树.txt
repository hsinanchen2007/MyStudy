### 解题思路
写一个测量树高的函数（递归）
判断是不是平衡二叉树的函数也要递归写

递归的递归

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

int height(struct TreeNode* Root)
{
    if(Root==0)return 0;
    else
    {
        int leftHeight=height(Root->left);
        int rightHeight=height(Root->right);
        return leftHeight>rightHeight?leftHeight+1:rightHeight+1;
    }
}

bool isBalanced(struct TreeNode* root){
    if(root==0)return 1;
    else
    {
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        if(leftHeight-rightHeight>1||rightHeight-leftHeight>1)
            return 0;
        else
        return isBalanced(root->left)&&isBalanced(root->right);
    }

}
```