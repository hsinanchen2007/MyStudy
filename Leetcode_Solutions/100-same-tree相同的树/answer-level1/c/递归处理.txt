### 解题思路
三种情况
1 两个树均为空，true
2 一棵树为空，另一棵树非空，false
3 两棵树非空，但节点数值不同，false，数值相同true

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
    if((p == NULL) && (q == NULL))
    {
        return true;
    }

    if(((p != NULL) && (q == NULL)) || ((p == NULL) && (q != NULL)))
    {
        return false;
    }
 
    if(p->val != q->val)
    {
        return false;
    }
    else
    {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}
```