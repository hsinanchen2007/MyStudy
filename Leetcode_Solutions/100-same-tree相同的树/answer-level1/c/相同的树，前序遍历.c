### 解题思路


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

bool PreOrder(struct TreeNode *T1, struct TreeNode *T2)
{
    if (T1 == NULL && T2 == NULL) {
        return true;
    } 

    if (T1 != NULL && T2 != NULL && T1->val == T2->val) {
        if (PreOrder(T1->left, T2->left) == false) {
            return false;
        }
        if (PreOrder(T1->right, T2->right) == false) {
            return false;
        } 
    } else {
        return false;
    }

    return true;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    return PreOrder(p, q);
}
```