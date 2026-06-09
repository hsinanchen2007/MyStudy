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
bool cmp(struct TreeNode* p,struct TreeNode* q)   //递归判左子树的左值和右子树的右值，左子树的右值右子树的左值是否相等
{
    if(p == NULL && q == NULL)
        return true;
    else if(p == NULL || q == NULL)
        return false;
    else if(p->val != q->val)
        return false;
    return cmp(p->left,q->right) && cmp(p->right,q->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if(root == NULL)
        return true;
    return cmp(root->left,root->right);
}
```