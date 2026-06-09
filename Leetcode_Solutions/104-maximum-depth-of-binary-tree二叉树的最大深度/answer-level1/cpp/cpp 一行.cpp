```
class Solution {
public:
    inline int maxDepth(TreeNode* root) {
        return root == nullptr ? 0 : max(maxDepth(root->left)+1, maxDepth(root->right)+1);
    }
};
```
