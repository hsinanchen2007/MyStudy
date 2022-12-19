

### 代码

```cpp
class Solution {
public:
	TreeNode* invertTree(TreeNode* root)
	{
		if (root == NULL) return root;
		invertTree(root->right);
		invertTree(root->left);
		TreeNode* temp;
		temp = root->right;
		root->right = root->left;
		root->left = temp;
		return root;
	}
};
```