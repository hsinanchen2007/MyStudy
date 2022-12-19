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

int Deep(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    int n1 = 1 + Deep(root->left);
    int n2 = 1 + Deep(root->right);
    return n1 > n2 ? n1 : n2;
}
bool isBalanced(struct TreeNode* root)
{
    if(root == NULL)
        return true; 
    int left = Deep(root->left) + 1;
    int right = Deep(root->right) + 1;
    
    return abs(left-right) < 2 && isBalanced(root->left) && isBalanced(root->right);  //递归判左右子树的左右子树
}
```