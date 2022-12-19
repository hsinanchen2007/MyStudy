递归向下只有三种可能：
1. 当前节点为空，返回0；
2. 当前节点的左子节点是左叶子，则返回左叶子值和右子树之和；
3. 其他任何情况返回左子树和右子树之和；
```
	int sumOfLeftLeaves(TreeNode* root) {
		if (root != NULL) {
			if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
				return root->left->val;
			}
			return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
		}
		else {
			return 0;
		}
	}
```
