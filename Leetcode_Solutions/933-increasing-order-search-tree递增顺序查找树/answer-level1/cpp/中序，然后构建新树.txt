```
class Solution {
public:
    TreeNode* p = new TreeNode(0);
    TreeNode* tree = p;
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)
            return tree;
        increasingBST(root -> left);
        
        TreeNode* t = new TreeNode(0);
        p -> right = t;
        p = p -> right;
        p -> val = root -> val;
        
        increasingBST(root -> right);
        return tree -> right;
    }
};
```