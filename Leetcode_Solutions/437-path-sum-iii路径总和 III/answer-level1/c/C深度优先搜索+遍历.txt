int num=0;

int pathSum(struct TreeNode* root, int sum){
    num=0;
    d(root,sum);
    return num;
}

void d(struct TreeNode* root, int target){
    if(root!=NULL){
        dfs(root,0,target);
        d(root->left,target);
        d(root->right,target);
    }
}

void dfs(struct TreeNode* root, int sum, int target){
    if(root==NULL)
        return;
    sum=sum+root->val;
    if(sum==target){
        num++;
    }
    dfs(root->left,sum,target);
    dfs(root->right,sum,target);
}