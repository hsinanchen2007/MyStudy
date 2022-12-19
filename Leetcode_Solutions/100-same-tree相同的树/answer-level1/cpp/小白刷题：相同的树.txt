递归判断，相当于先序遍历

出口为均为空结点（true）、均为非空结点但val不同（false）、一空结点一非空结点（false）

代码：
```
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p != NULL && q != NULL && p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }
};
```
