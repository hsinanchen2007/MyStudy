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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* tmp = root;
        TreeNode* pre = root;
        while(tmp){
            if(tmp->val < val){
                pre = tmp;
                tmp = tmp->right;
            }else if (tmp->val > val){
                pre = tmp;
                tmp = tmp->left;
            }
        }
        TreeNode* node = new TreeNode(val);
        if (pre->val < val){
            pre->right = node;
        } else {
            pre->left = node;
        }
        return root;
    }
};