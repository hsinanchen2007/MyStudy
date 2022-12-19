class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)return 0;
        return Depth(root,1);
    }
    int Depth(TreeNode* root,int height)
    {
        int a = 0, b = 0;
        if(root->left==NULL&&root->right==NULL) return height;
        if(root->left!=NULL) a = Depth(root->left,height+1);
        if(root->right!=NULL) b = Depth(root->right,height+1);
        return a>b?a:b;
        
    }
};