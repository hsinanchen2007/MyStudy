看评论大神整理

void Inorder(struct TreeNode*root,int *returnSize,int *res) 
{ 
	if(!root) return; 
	Inorder(root->left,returnSize,res); 
	res[(*returnSize)++]=root->val; 
	Inorder(root->right,returnSize,res); 
} 

int TreeSize(struct TreeNode*root) 
{
	if(!root) return 0; 
	return TreeSize(root->left)+TreeSize(root->right)+1; 
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{ 
	int size=TreeSize(root); 
	int *res=malloc(sizeof(int)*size); 
	memset(res,0,size); 
	*returnSize=0; 
	Inorder(root,returnSize,res); 
	return res; 
} 
