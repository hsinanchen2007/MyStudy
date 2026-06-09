### 解题思路
此处撰写解题思路
1、采用递归的策略，进行迭代判定；

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
    else if((p == NULL) || (q == NULL))
    {
        return false;
    }
    else
    {
        if(p->val != q->val)
        {
            return false;
        }
        else
        {
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
    }
}
```