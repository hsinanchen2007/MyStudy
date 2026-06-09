```
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int mx = 0;
        find(root, mx);
        return mx;
    }
    int find(TreeNode* root, int& mx)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = find(root->left, mx);
        int right = find(root->right, mx);
        int cmx = 0;
        int ret = 1;
        if(left > 0  && root->left->val == root->val)
        {
            cmx += left;
            ret += left;
        }
        if(right > 0 && root->right->val == root->val)
        {
            cmx += right;
            if(right+1 > ret)
            {
                ret = right + 1;
            }
        }
        if(cmx > mx)
        {
            mx = cmx;
        }
        return ret;
    }
};
```
