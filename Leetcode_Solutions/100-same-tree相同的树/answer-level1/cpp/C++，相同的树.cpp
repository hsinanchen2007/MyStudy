### 解题思路
相同的树：根节点相同，左右子树分别相同
tips: 两个空树是same trees

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
    if (p == NULL & q == NULL) return true;
    if (p == NULL || q == NULL || (p->val != q->val)) return false;
    return (isSameTree(p->left, q->left) & isSameTree(p->right, q->right));
}
```