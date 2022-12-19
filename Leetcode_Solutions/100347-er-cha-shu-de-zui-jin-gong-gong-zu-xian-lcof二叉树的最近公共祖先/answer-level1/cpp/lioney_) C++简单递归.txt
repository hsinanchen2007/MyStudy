```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root->val == p->val || root->val == q->val) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // p, q在root两侧
        if(left && right) return root;
        // p, q都在root左侧
        else if(left && !right) return left;
        // p, q都在root右侧
        else if(!left && right) return right;
        return nullptr;
    }
};
```
