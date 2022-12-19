```c++
bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        else {
            bool left = true, right = true;
            
            if (root->left) {
                left = root->val == root->left->val && isUnivalTree(root->left);
            }
            
            if (root->right) {
                right = root->val == root->right->val && isUnivalTree(root->right);
            }   
            
            return left && right;   
        }
        
        return false;
    }