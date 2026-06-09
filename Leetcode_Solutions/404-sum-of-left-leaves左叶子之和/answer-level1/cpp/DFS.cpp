简单递归即可

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
    int res=0;
    void helper(TreeNode* &root){
        //递归终止条件
        if(!root){
            return ;
        }
        //记录左叶子
        if(root->left && root->left->left==nullptr && root->left->right==nullptr){
            res+=root->left->val;
        }
        helper(root->left);
        helper(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root);
        return res;
    }
};

```
