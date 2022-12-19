### 解题思路
递归

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


int minDepth(struct TreeNode* t){
    if(!t)
        return 0;
    if(!t->left && !t->right)
        return 1;
    if(!t->left)
        return minDepth(t->right) + 1;
    if(!t->right)
        return minDepth(t->left) + 1;
    return fmin(minDepth(t->left), minDepth(t->right)) + 1;
}
```