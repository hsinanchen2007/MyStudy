class Solution {
public:
    int maxDepth(TreeNode* root, int& res) {
        int lDep = 0, rDep = 0;
        if (root->left != NULL) lDep = maxDepth(root->left, res) + 1;
        if (root->right != NULL) rDep = maxDepth(root->right, res) + 1;
        res = max(res, lDep + rDep);
        return max(lDep, rDep);
    }

    int diameterOfBinaryTree(TreeNode *root) {
        int res = 0;
        if (root == NULL) return 0;
        maxDepth(root, res);
        return res;
    }
};