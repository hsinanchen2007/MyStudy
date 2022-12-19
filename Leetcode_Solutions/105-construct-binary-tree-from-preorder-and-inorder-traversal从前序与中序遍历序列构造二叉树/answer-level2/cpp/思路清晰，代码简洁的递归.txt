TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder){
	return recursion(preorder,inorder,0,preorder.size(),0);
}
TreeNode* recursion(vector<int>& preorder,vector<int>& inorder,int pre_left,int length,int in_left){
if(length==0)
	return NULL;
TreeNode* root=new TreeNode(preorder[pre_left]);
int index=in_left;
while(inorder[index]!=preorder[pre_left])
{
	index++;
}
int left_len=index-in_left;
root->left=recursion(preorder,inorder,pre_left+1,left_len,in_left);
root->right=recursion(preorder,inorder,pre_left+left_len+1,length-left_len-1,index+1);
return root;
}