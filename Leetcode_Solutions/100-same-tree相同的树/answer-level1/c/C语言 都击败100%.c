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

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p!=NULL && q!=NULL)
    {
        if(p->val != q->val)
        {
            return false;
        }
    }else if((q&&!p)||(!q&&p)){
        return false;
    }else{
        return true;
    }
    
    if(isSameTree(p->left,q->left)==false)
        {
            return false;
        }
    if(isSameTree(p->right,q->right)==false)
        {
            return false;
        }
    return true;
}
```