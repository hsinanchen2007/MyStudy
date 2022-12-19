```
bool isSameTree(TreeNode* p, TreeNode* q) {
        return p == NULL || q == NULL ? p == q : (p->val != q->val ? false : isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
```
