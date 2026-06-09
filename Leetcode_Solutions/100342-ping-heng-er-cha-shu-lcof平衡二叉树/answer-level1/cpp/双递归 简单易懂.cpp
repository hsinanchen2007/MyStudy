
```
bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL&&root->right==NULL) return true;
        return isBalanced(root->left)&&isBalanced(root->right)&&abs(maxDepth(root->left)-maxDepth(root->right))<=1;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
```
