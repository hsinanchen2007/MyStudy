
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int depthl = maxDepth(root->left);
        int depthr = maxDepth(root->right);
        int rs = depthl - depthr;
        if(rs<-1||rs>1)
            return false;
        else
            return isBalanced(root->left)&&isBalanced(root->right);
    }
    int maxDepth(TreeNode* node) {
        int maxdepth = 0;
        if(node == NULL)
            return 0;
        else
        {
            maxdepth = max(maxDepth(node->left),maxDepth(node->right));
            return maxdepth+1;
        }
    }    
};