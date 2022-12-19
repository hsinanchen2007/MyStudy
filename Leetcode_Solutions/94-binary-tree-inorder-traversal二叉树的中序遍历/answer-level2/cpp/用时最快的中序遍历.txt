写了一个用时最快的中序遍历


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
// private:vector<int> a;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> a;
        if(root != nullptr)
        {
            vector<int> left = inorderTraversal(root->left);
            a.insert(a.begin(), left.begin(), left.end());
            a.push_back(root->val);
            vector<int> right = inorderTraversal(root->right);
            a.insert(a.end(), right.begin(), right.end());
        }
        return a;
    }
};