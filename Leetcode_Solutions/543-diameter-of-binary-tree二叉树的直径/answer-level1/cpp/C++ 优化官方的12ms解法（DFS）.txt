```cpp
class Solution {
public:
    int ans = 0;
    int help(TreeNode* rt) {
        if (rt == nullptr) return -1;
        
        int l = 1 + help(rt->left);
        int r = 1 + help(rt->right);
        ans = max(ans, l + r);
        return max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        help(root);
        return ans;
    }
};
```