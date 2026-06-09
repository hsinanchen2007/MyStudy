### 解题思路
此处撰写解题思路

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


bool isUnivalTree(struct TreeNode* root)
{
    if(root == NULL)
        return true;
    if(root->left && root->left->val != root->val)   //判根 和左
        return false;
    if(root->right && root->right->val != root->val) //判根 和右
        return false;
    return isUnivalTree(root->left) &&     //递归判断其余左子树和右子树，一旦相同返回true 不同则返回flase
           isUnivalTree(root->right);

}
```