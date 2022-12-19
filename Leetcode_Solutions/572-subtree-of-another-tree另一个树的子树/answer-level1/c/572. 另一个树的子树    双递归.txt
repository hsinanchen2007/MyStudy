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


bool equal(struct TreeNode* a,struct TreeNode* b){
    if(a == NULL && b == NULL)
        return true;

    if(a == NULL || b == NULL)
        return false;

    if(a->val == b->val)     
        return equal(a->left,b->left) && equal(a->right,b->right);
    else
        return false;
}


bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if(s == NULL)
        return false;
    
    if(s->val == t->val && equal(s,t))
         return true;
    else
        return isSubtree(s->left,t) ||  isSubtree(s->right,t);
}
```