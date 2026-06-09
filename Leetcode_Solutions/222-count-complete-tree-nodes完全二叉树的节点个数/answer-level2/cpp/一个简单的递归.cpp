```
class Solution {
public:
    int sum=1;
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left)
            sum=countNodes(root->left)+1;
        if(root->right)
            sum=countNodes(root->right)+1;
        return sum;
    }
};
```
