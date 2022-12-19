官方题解递归中的判断语句可以优化，因为当p和q都是空指针的时候它们是相等的：

```
class Solution {
  public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == q)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```
