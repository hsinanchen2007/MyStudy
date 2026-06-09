```
 bool isSameTree(TreeNode* p, TreeNode* q) {
TreeNode* pt = p;
	TreeNode* qt = q;
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	while (pt||qt||s1.size()||s2.size())//同时对两棵树前序遍历
	{
		while (pt||qt)
		{
			if (!pt||!qt||pt->val != qt->val)//任意一棵树为空或是结点值不相等
				return false;
			s1.push(pt->right);
			s2.push(qt->right);
			pt = pt->left;
			qt = qt->left;
		}
		pt = s1.top();
		s1.pop();
		qt = s2.top();
		s2.pop();
	}
	return true;
    }
```
