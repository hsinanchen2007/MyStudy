学习官方的递归解法
class Solution {
    int ans;
    int depath(TreeNode* rt)
    {
        if(rt == NULL)
            return 0;
        int Left = depath(rt->left);
        int Right = depath(rt->right);
        int arrowLeft = 0;
        int arrowRight = 0;
        if(rt->left != NULL && rt->val == rt->left->val)
            arrowLeft += Left + 1;
        if(rt->right != NULL && rt->val == rt->right->val)
            arrowRight += Right + 1;
        ans = max(ans, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        depath(root);
        return ans;
    }
};