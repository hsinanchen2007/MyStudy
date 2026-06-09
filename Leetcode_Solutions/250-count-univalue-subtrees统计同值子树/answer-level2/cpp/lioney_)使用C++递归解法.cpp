
```
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
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    
    bool helper(TreeNode* root, int& res) {
        if(!root) return true;
        bool left = helper(root->left, res);
        bool right = helper(root->right, res);
        if(root->left && root->left->val != root->val || root->right && root->right->val != root->val)
            return false;
        if(left && right) res += 1;
        return true;
    }
};

