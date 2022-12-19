``` C++
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
    bool isSymmetric(TreeNode* root) {
        return isTwoTreeSymmetric(root,root);        
    }
    bool isTwoTreeSymmetric(TreeNode* r1,TreeNode* r2)
    {
        if(r1==NULL&&r2==NULL) return true;
        if(r1==NULL||r2==NULL) return false;
        if(r1->val==r2->val)
            return isTwoTreeSymmetric(r1->left,r2->right)&&isTwoTreeSymmetric(r1->right,r2->left);
        else 
            return false;
    }
};
```