```
class Solution {
public:
    bool ismirror (TreeNode* p, TreeNode* q) {
        if (p==nullptr && q==nullptr) return true;
        else if (p!=nullptr && q==nullptr || p==nullptr && q!=nullptr) return false;
        else return p->val==q->val && ismirror (p->left, q->right) && ismirror (p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr) return true;
        return ismirror(root->left,root->right);
    }
};
```
