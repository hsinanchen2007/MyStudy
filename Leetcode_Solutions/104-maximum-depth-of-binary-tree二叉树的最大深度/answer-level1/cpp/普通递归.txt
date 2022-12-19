树的最大深度是它左子树和右子树深度中的最大值再+1，根为空时最大深度为0。
```C++ []
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root?max(maxDepth(root->left),maxDepth(root->right))+1:0;
    }
};
```
