```
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return  false;
        else{
            if((root->val==sum)&&(root->left==NULL&&root->right==NULL))//首先得确保到这一步满足和的要求 还要判断是否是叶子结点
                return true;
            else
                return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
            
        }
    }
};
```
