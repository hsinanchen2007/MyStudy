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
    void preAccess(TreeNode* root, string flag, int & left_sum)
    {
        if(root == NULL) return;
        if(flag == "left" && root->left == NULL && root->right == NULL)
        {
            left_sum += root->val;
        }
        preAccess(root->left, "left", left_sum);
        preAccess(root->right, "right", left_sum);
        
        return;
    }
        
    int sumOfLeftLeaves(TreeNode* root) {
        int left_sum = 0;
        preAccess(root, "root", left_sum);
        return left_sum;
    }
};
```