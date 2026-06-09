```C++ []
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        depth(root);
        return ans;
      
    }

    int depth(TreeNode* root)
    {
        if(root == NULL) return -1;
        int l_depth = depth(root->left);
        int r_depth = depth(root->right);
        ans = max(ans, l_depth+r_depth+2);
        return l_depth > r_depth? l_depth+1: r_depth+1;
    }
};
```



