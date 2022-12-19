```
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        }
        TreeNode* ret = t1 == NULL ? t2 : t1;
        int num1 = t1 == NULL ? 0 : t1->val;
        int num2 = t2 == NULL ? 0 : t2->val;
        ret->val = num1 + num2;
        ret->left = mergeTrees(t1 == NULL ? NULL : t1->left, t2 == NULL ? NULL : t2->left);
        ret->right = mergeTrees(t1 == NULL ? NULL : t1->right, t2 == NULL ? NULL : t2->right);
        return ret;
    }
};
```
还是官方题解写的简单点