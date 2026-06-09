先后序遍历，全部存在栈里，在从底部找，就能找到公共祖先节点。

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	if (root == NULL)
		return NULL;
	stack<TreeNode*> record;
	stack<TreeNode*> help;
	record.push(root);
	while (!record.empty())
	{
		TreeNode* cur = record.top();
		help.push(cur);
		record.pop();

		if (cur->left != NULL)
			record.push(cur->left);
		if (cur->right != NULL)
			record.push(cur->right);
	}
	while (!help.empty())
	{
		TreeNode* node = help.top();

		if (node->left != NULL && node->left->val == p->val)
			p->val = node->val;
		if (node->right != NULL && node->right->val == p->val)
			p->val = node->val;
		if (node->left != NULL && node->left->val == q->val)
			q->val = node->val;
		if (node->right!= NULL && node->right->val == q->val)
			q->val = node->val;

		if (p->val == q->val)
			return p;

		help.pop();
	}
	return NULL;
}