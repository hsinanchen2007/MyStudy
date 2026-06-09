int TreeSize(struct TreeNode* root)
{
    if(!root)
        return 0;
    return TreeSize(root->left)+TreeSize(root->right)+1;
}
int TreeTravel(struct TreeNode* root, int *OutPut,int* returnSize)
{
    if(root)
    {
        TreeTravel(root->left,OutPut,returnSize);
        *(OutPut+(*returnSize)++)=root->val;
        TreeTravel(root->right,OutPut,returnSize);
    }
    return 0;
}


int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int size=TreeSize(root);
    *returnSize=0;
    int *OutPut=(int *)malloc(size*sizeof(int));
    TreeTravel(root,OutPut,returnSize);
    return OutPut;
    
}