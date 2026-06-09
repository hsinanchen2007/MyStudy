```
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int d = 0;
        return helper(root, d);
    }
    bool helper(TreeNode *root, int &d) {
        if (!root) return true;
        int dl = 0, dr = 0;
        return helper(root->left, dl) && helper(root->right, dr) && abs(dl - dr) < 2 &&
            (d = max(dl, dr) + 1);
    }
};
```