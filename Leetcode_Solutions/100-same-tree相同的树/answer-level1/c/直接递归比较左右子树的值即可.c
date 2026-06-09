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

bool compare(struct TreeNode* p, struct TreeNode* q)
{
    if(p == NULL && q == NULL)
        return true;
    if(p == NULL || q == NULL)
        return false;
    if(p->val != q->val)
        return false;
    return compare(p->left,q->left) &&  compare(p->right,q->right);   //递归比较左右子树的值
}
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    return compare(p,q);
}
```