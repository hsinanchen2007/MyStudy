我发现凡是树的题，基本上往递归上扯都能给你思路。
4行解决问题
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if( !root ) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1+(left>right?left:right);
    }
};
```
