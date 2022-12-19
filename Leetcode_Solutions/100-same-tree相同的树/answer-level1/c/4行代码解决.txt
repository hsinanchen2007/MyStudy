- 执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户

- 内存消耗 :7.1 MB, 在所有 C 提交中击败了100.00%的用户
```
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val    != q->val)    return false;
    return isSameTree(p->left, q->left) ? isSameTree(p->right, q->right) :  false;
}
```