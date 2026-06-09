### 解题思路
暴力遍历，不过代码比较简短

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
    bool rlt;
    if (p == NULL && q == NULL) {
        return true;
    }
    if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
        return false;
    } 
    return isSameTree(p->left, q->left) && 
            p->val == q->val && 
            isSameTree(p->right, q->right);
}
```