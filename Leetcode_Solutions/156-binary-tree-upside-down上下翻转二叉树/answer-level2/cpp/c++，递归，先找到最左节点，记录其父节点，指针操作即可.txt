class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            return root;
        }
        TreeNode* pos = root;
        TreeNode* pre = root;
        while(pos->left) {
            pre = pos;
            pos = pos->left;
        }
        pos->left = pre->right;
        pre->left = pre->right = NULL;
        pos->right = upsideDownBinaryTree(root);
        return pos;
    }
};