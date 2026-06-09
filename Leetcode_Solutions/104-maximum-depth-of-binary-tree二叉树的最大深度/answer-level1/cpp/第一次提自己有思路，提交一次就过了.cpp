class Solution {
public:
    int maxdepth;
    int maxDepth(TreeNode* root) {
        maxdepth = 0;
        if(root!= NULL){
            int leftdep =  maxDepth(root->left);
            int rightdep = maxDepth(root->right);
            maxdepth = (leftdep<rightdep)?rightdep+1:leftdep+1;
        }
        return maxdepth;  
    }
};

通过模仿之前做过的题目的思路，在外面写了一个maxdepth;
整体思路也是递归操作。