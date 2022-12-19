二叉树的深度等于其左子树的深度和右子树的深度当中最大的哪一个
递归求解左子树和右子树深度，判断即可
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left_depth =  maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return (left_depth > right_depth?left_depth:right_depth)+1;
    }
};