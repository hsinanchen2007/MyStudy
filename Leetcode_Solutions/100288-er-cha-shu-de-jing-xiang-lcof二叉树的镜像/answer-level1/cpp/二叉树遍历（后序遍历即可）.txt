![\[{64A0W2D1M$YJ4ZEJU9X75.png](https://pic.leetcode-cn.com/2bc9158e59595beaefb8998e545d0907c44f30511caaa61d2b558ee8712c0e9c-%5B%7B64A0W2D1M$YJ4ZEJU9X75.png)
```
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        function(root);
        return root;
    }
    void function(TreeNode* &root){
        if(root==NULL)
            return;
        function(root->left);
        function(root->right);
        swap(root->left,root->right);
    }
};
