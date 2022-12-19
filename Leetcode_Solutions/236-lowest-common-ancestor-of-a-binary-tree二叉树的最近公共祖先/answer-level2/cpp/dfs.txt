```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* left_res = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_res = lowestCommonAncestor(root->right, p, q);
        if (left_res && right_res) return root;
        else if (left_res) return left_res;
        return right_res;
    }
};