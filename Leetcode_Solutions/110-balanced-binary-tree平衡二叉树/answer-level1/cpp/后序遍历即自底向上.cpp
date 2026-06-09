```
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if( !root )
            return true;
        int depth = 0;
        return is_Balanced(root, depth);
    } 
    bool is_Balanced(TreeNode* root, int &depth)
    {
        if( !root )
        {
            depth = 0;
            return true;
        }
        int l, r;
        if(is_Balanced(root->left, l) && is_Balanced(root->right, r))
        {
            int gap = abs(l - r);
            if(gap <= 1)
            {
                depth = max(l ,r) + 1;
                return true;
            }
        }
        return false;
    }
};
```
