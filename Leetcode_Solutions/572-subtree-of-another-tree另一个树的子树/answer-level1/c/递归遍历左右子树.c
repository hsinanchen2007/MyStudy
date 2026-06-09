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

bool compare(struct TreeNode* root1,struct TreeNode* root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    if(root1->val != root2->val)
        return false;
    return compare(root1->left,root2->left) && compare(root1->right,root2->right);  //递归比较左右  
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
     if(s == NULL && t != NULL)   //s已经到底
         return false;
    return compare(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);  //判 根  左  右
}
```