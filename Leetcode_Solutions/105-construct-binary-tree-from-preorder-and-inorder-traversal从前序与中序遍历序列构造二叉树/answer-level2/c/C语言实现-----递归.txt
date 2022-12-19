struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
	int left_len = 0;
	struct TreeNode *res = NULL;
	
	if ((preorder == NULL)||(preorderSize == 0)||(inorder == NULL)||(inorderSize == 0))
	{
		return res;
	}

	res = (struct TreeNode*)malloc(sizeof(struct TreeNode)*1);
	res->val = *preorder;
	res->left = NULL;
	res->right = NULL;

	if ((preorderSize == inorderSize)&&(inorderSize == 1))
	{
		return res;
	}

	left_len = 0;
	while (left_len != inorderSize)
	{
		if (res->val == inorder[left_len])
		{
			break;
		}
		left_len++;
	}
	if (left_len > 0)
	{
		res->left = buildTree(preorder+1, left_len, inorder, left_len);
	}
	if (left_len < inorderSize)
	{
		res->right = buildTree(preorder+(left_len+1), preorderSize-(left_len+1), inorder+(left_len+1), inorderSize-(left_len+1));
	}
	return res;
}