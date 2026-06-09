```
class Solution {
public:
	/*递归查找算法*/
	TreeNode* searchBST(TreeNode* root, int val) {
		if (!root)
			return NULL;
		if (root->val == val)
			return root;
		else if (val > root->val)
			return searchBST(root->right, val);
		else
			return searchBST(root->left, val);
	}
};
```

```
class Solution {
public:
	/*非递归查找算法*/
	TreeNode* searchBST(TreeNode* root, int val) {
		while (root && root->val != val) {
			if (val > root->val)
				root = root->right;
			else
				root = root->left;
		}
		return root;
	}
};
```

