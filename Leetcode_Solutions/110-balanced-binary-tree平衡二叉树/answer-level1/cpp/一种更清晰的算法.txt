```
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool isB = true;
        helpDFS(root, isB);
        return isB;
    }

    int helpDFS(TreeNode* root, bool& isB) {
        if (!root) return -1;

        int deep_left = helpDFS(root->left, isB);
        int deep_right = helpDFS(root->right, isB);
        if (abs(deep_left - deep_right) > 1) isB = false;
        return max(deep_left, deep_right) + 1;
    }
};
```
