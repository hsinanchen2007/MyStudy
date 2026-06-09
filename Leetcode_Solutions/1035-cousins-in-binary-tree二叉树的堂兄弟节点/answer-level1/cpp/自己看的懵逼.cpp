
```
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
    bool isCousins(TreeNode* root, int x, int y) {

        int lparent = 0;
        int rparent = 0;       
        int ldepth = DepthTree(root, 0, x, lparent, root->val);
        int rdepth = DepthTree(root, 0, y, rparent, root->val);
        return (lparent != rparent)&&(ldepth == rdepth);
    }
    int DepthTree(TreeNode* root, int depth, int val, int& parent, int parentval)
    {
        int l, r;
        if (!root)
            return 0;
        if (root->val == val)
        {
            parent = parentval;
            return depth;
        }
        l = DepthTree(root->left, depth + 1, val, parent, root->val);
        r = DepthTree(root->right, depth + 1, val, parent, root->val);
        return max(l, r);
    }
};
```

