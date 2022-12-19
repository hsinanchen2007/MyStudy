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
bool compare(struct TreeNode* p, struct TreeNode* q) //递归判断左子树的左值和右子树的右值，右子树的左值和左子树的右值
{
    if(p == NULL && q == NULL)
        return true;
    if(p == NULL || q == NULL)
        return false;
    if(p->val != q->val)
        return false;
    return compare(p->left,q->right) && compare(p->right,q->left);   
}


bool isSymmetric(struct TreeNode* root)
{
    if(root == NULL)
        return true;
    return compare(root->left,root->right);   
}
```