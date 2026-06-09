
```
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        return isSubtree(s->left, t) || SameTree(s, t) || isSubtree(s->right, t);
    }

    bool SameTree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        return s->val == t->val && SameTree(s->left, t->left) && SameTree(s->right, t->right);
    }
```
遍历s树判断每个节点是否与t树相同