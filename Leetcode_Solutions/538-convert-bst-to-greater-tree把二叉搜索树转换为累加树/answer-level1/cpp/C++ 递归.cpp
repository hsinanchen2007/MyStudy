```c++
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
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        int acc = 0;
        return convertBST(root, acc);
    }

    TreeNode* convertBST(TreeNode* root, int& acc) {
        if (!root) return nullptr;
        root->right = convertBST(root->right, acc);
        root->val += acc;
        acc = root->val;
        root->left = convertBST(root->left, acc);
        return root;
    }
};
```