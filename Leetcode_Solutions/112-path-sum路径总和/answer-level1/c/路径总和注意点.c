bool hasPathSum(struct TreeNode* root, int sum){ 
    if(root==NULL)
        return(false);
    if(root->left==NULL&&sum==root->val&&root->right==NULL)
        return(true);
    sum=sum-(root->val);
    bool l=hasPathSum(root->left,sum);
    bool r=hasPathSum(root->right,sum);
    return(l||r);

}
代码如上，需要注意的是，当树为空，sum为零时，默认答案输出为false
因此判断为真要在叶子结点上做。