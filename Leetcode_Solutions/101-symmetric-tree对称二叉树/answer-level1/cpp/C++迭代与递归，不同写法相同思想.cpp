### 1.递归版本
    递归版本是比较容易理解的，清楚解决问题的最基本步骤即可。
```
bool isSymmetric(TreeNode* root) {
	if (!root) 
		return true;
	return isMirror(root, root);
}

bool isMirror(TreeNode* n1, TreeNode* n2)
{
	if (n1 == NULL && n2 == NULL)
		return true;
	if ( n1 == NULL || n2 == NULL )
		return false;
	
		return (n1->val == n2->val) && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
	
}
```
### 2.迭代版本
    迭代版本可以借助栈来实现，与递归思想基本一致。需要注意的是循环终止条件。
```
bool isSymmetric(TreeNode* root) {
	if (!root) return true;
	std::stack<TreeNode*> s;
	if (root->left) 
        s.push(root->left);
    else
        s.push(NULL);
	if (root->right) 
        s.push(root->right);
    else
        s.push(NULL);
	while (!s.empty())
	{
		TreeNode* n1 = s.top();
		s.pop();
		TreeNode* n2 = s.top();
		s.pop();
		if (!n1 && !n2)
			continue;
		if (!n1 || !n2)
			return false;
		if (n1->val != n2->val)
			return false;
		if (n1->left)
			s.push(n1->left);
		else
			s.push(NULL);
		if (n2->right) 
			s.push(n2->right);
		else 
			s.push(NULL);
		if (n1->right) 
			s.push(n1->right);
		else
			s.push(NULL);
		if (n2->left) 
			s.push(n2->left);
		else
			s.push(NULL);
	}
	return true;
}
```

