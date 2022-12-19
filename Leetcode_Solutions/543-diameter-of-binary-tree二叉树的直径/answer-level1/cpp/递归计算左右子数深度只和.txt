```
class Solution {
public:
    int max_depth = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return max_depth;
    }
    int depth(TreeNode* root)
    {
        int depth_left = 0;
        int depth_right = 0;
        if(root == NULL)
        {
            return 0;
        }
        
        depth_left = depth(root->left);
        depth_right = depth(root->right);
        if(depth_left+depth_right > max_depth)
            max_depth = depth_left+depth_right;
        return depth_left>depth_right ? depth_left+1 : depth_right+1;
    }
};
```
