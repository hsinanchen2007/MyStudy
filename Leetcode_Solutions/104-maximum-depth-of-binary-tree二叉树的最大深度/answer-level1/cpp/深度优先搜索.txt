理解二叉树的作用
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int left1=maxDepth(root->left) ;
        int right1=maxDepth(root->right);
        return max(left1,right1)+1;
    }
};
```

