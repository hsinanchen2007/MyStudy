```C++ []
class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if (root != NULL) {
			TreeNode* tmp = mirrorTree(root->left);
			root->left = mirrorTree(root->right);
			root->right = tmp;
		}
		return root;
	}
};
```
