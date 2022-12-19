```
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
			return false;

		return isSymmetric_childcode(root->left, root->right);
	}

	bool isSymmetric_childcode(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr)
			return true;
		if ((left && !right) || (!left && right))
			return false;

		if (left->val == right->val)
		{
			return isSymmetric_childcode(left->left, right->right) && isSymmetric_childcode(left->right, right->left);
		}

		return false;
	}
```
