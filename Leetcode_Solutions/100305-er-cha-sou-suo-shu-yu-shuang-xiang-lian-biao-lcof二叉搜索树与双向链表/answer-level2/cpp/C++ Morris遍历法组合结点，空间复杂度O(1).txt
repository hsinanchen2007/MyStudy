如果面试，最快可以使用中序遍历方法写出代码，如果要求空间复杂度O(1)且非递归，考虑Morris遍历方法。
```
Node* treeToDoublyList(Node* root) {
	if (!root) return root;
	Node* pre = NULL, * cur = root, *head = NULL, *morrisRight = NULL;
	while (cur)
	{
		morrisRight = cur->left;
		if (morrisRight != NULL)
		{
			while (morrisRight->right && morrisRight->right != cur)
				morrisRight = morrisRight->right;
			if (!morrisRight->right)
			{
				morrisRight->right = cur;
				cur = cur->left;
				continue;
			}
			else
			{
				cur->left = morrisRight;
				pre = cur;
				cur = cur->right;
				continue;
			}
		}
		if (!head) head = cur;
		else
		{
			pre->right = cur;
			cur->left = pre;
		}
		pre = cur;
		cur = cur->right;
	}
	pre->right = head;
	head->left = pre;
	return head;
}
```
时间复杂度O(N),空间复杂度O(1)