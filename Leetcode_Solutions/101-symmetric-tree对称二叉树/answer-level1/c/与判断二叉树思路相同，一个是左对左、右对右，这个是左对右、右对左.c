### 解题思路
与判断二叉树思路相同,
如果相同的话，为左分支对比左分支，右分支对比右分支
那么对称则是，左对右， 右对左

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
    if (!p && !q) return true;
    if ((p && !q) || (!p && q) || p->val != q->val) return false;
    return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
    if (!root) return true;
    return isSameTree(root->left, root->right);
}
```