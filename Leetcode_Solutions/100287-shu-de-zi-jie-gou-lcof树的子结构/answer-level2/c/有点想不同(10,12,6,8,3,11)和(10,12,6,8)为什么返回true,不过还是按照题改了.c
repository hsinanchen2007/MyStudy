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

bool compare(struct TreeNode* p,struct TreeNode* q)
{
    if(p == NULL && q == NULL)
        return true;
    if(p != NULL && q == NULL)   //应对(10,12,6,8,3,11)和(10,12,6,8)这种情况的
        return true;
    if(p == NULL && q != NULL)
        return false;
    if(p->val != q->val)
        return false;
    return compare(p->left,q->left) && compare(p->right,q->right);    
}




bool isSubStructure(struct TreeNode* A, struct TreeNode* B)
{
    if(A == NULL && B != NULL)
       return false;
    else if(A != NULL && B == NULL)
        return false;
    return compare(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);//用或，递归处理根，左子树，右子树只有有一个对上就true;
}
```