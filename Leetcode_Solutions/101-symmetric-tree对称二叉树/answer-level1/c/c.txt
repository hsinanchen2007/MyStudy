### 解题思路
此处撰写解题思路
注意迭代对称性。

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

bool find(struct TreeNode* root_left, struct TreeNode* root_right)
{
    if(root_left == NULL && root_right == NULL)
    {
        return true;
    }
    else if(root_left == NULL || root_right == NULL)
    {
        return false;
    }

    return ((root_left->val == root_right->val) && find(root_left->left, root_right->right) &&
    find(root_left->right, root_right->left));
}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL)
    {
        return true;
    }

    return find(root->left, root->right);
}
```