```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxLen = 0;
        if(root) {
            maxLen = max(maxDepth(root->left), maxDepth(root->right)) + 1;
        };
        return maxLen;
    }
};
```
