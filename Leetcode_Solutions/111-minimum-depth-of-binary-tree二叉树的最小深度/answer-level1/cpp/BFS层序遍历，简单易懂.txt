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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return BFS(root, 0) + 1;
    }

    int BFS(TreeNode* root, int level)
    {
        if (root == nullptr) {
            return INT_MAX;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return level;
        }
        level++;
        return min(BFS(root->left, level), BFS(root->right, level));
    }
};