### 解题思路
- 一个为空一个不为空的情况
   * 返回false
- 都为空
   * 返回true
- 都不为空时观察左右子树是否相等，如果相等再比较当前节点是否相等
   * 只有都相等的时候才返回为true
   * 其他情况均为false(如左子树不相等，右子树不相等，当前节点不相等)

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
    if((p == NULL && q != NULL) || (p != NULL && q == NULL))
    {
        return false;
    }
    if(p == NULL && q == NULL)
    {
        return true;
    }
    if(isSameTree(p->left,q->left))
    {
        if(isSameTree(p->right,q->right))
        {
            if(p->val == q->val)
            {
                return true;
            }
            
        }
    }
    return false;
}
```