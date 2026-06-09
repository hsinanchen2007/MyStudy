### 解题思路
前序遍历

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
    if (p == NULL && q == NULL) return true;
    else if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;

    bool v;
    if (p->val == q->val) v = true;
    else v = false;

    bool l = isSameTree(p->left, q->left);
    bool r = isSameTree(p->right, q->right);
    if (v == true && l == true && r == true) return true;
    else return false;
}
```