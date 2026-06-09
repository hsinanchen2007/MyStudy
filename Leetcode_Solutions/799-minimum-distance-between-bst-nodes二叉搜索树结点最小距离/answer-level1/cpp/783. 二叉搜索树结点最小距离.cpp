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
    int minDiffInBST(TreeNode* root) {
        int res;
        if(!root) return INT_MAX;
        if(!root->left && !root->right) return INT_MAX;
        
        TreeNode* lm;
        TreeNode* rm;
        if(root->left)
        {
            lm=root->left;
        while(lm->right)
            lm=lm->right;
        }
        if(root->right){
            rm=root->right;
        while(rm->left)
            rm=rm->left;
        }
        if(root->left && root->right)
            res=min(root->val- lm->val, rm->val -root->val);
        else if(root->left)
            res=root->val-lm->val;
        else
            res=rm->val -root->val;
        if(root->left)
            res=min(res, minDiffInBST(root->left));
        if(root->right) 
            res=min(res,minDiffInBST(root->right));
        return res;
    }
};
```
> 执行用时 : 4 ms, 在Minimum Distance Between BST Nodes的C++提交中击败了97.57% 的用户  
 80 内存消耗 : 11.4 MB, 在Minimum Distance Between BST Nodes的C++提交中击败了50.42% 的用户