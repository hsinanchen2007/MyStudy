### 解题思路
深度搜索基本原理：尽可能的往一条路进前进，如果失败就返回
在此题应用就是尽可能往左（或者右）前进，一旦错误立马返回。

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
    int ret ;
    if((p == NULL) ||(q == NULL))
    {
        if ((p == NULL)&&(q == NULL))
            return true;
        else 
            return false;
    }
    if (p->val == q->val)
        {
            ret =(isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
        }
    else 
        return false;
    return ret ;

}
```