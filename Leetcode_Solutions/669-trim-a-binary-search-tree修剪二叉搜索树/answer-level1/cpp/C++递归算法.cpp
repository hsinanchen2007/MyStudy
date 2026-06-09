```cpp
class Solution {
private:
    TreeNode* trim(TreeNode*& root, int L, int R) {
        if (!root) return nullptr;
        root->left = trim(root->left, L, R);
        root->right = trim(root->right, L, R);
        if (root->val < L) return root->right;
        if (root->val > R) return root->left;
        return root;
    }
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        return trim(root, L, R);
    }
};
```