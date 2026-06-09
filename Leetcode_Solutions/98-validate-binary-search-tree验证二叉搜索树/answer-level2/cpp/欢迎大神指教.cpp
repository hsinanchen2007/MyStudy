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
    bool isValidBST(TreeNode* root) {
        helper(root);
        if (count <= 1) {
            return true;
        }
        return isValid;
    }

    void helper(TreeNode* root)
    {
        if (root == nullptr || isValid == false) {
            return;
        }
        helper(root->left);
        count++;
        if (count == 1) {
            last = root->val;
        } else{
            if (root->val <= last) {
                isValid = false;
                return;
        }
        }       
        last = root->val;
        helper(root->right);
    }

private:
    int isValid = true;
    int last = INT_MIN;
    int count = 0;
};