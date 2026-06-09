void dfs(struct TreeNode* root, int *deep, int *value,int *max)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left != NULL)
    {
        (*deep)++;
        if(*deep > *max)
        {
            *max = *deep;
            *value = root->left->val;
        }
        dfs(root->left,deep,value,max);
        (*deep)--;
    }if(root->right != NULL)
    {
        (*deep)++;
        if(*deep > *max)
        {
            *max = *deep;
            *value = root->right->val;
        }
        dfs(root->right,deep,value,max);
        (*deep)--;
    }
}
int findBottomLeftValue(struct TreeNode* root){
    int deep = 0;
    int max = 0;
    int value = 0;

    value = root->val;
    dfs(root,&deep,&value,&max);

    return value;
}