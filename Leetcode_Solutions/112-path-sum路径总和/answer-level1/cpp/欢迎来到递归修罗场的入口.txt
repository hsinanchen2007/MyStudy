```
bool hasPathSum(TreeNode* root, int sum) {
        //注意空树的情况
        if(!root) return false;
        //递归终止
        if(!root->left && !root->right)
            return sum == root->val;
        //递归过程
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
```
