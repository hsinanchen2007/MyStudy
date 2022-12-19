### 解题思路
具体看代码

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool dfs(TreeNode* root) {
		if (!root->right && !root->left) return root->val == 0;
		bool left = true, right = true;
		if (root->left) left = dfs(root->left);
		if (root->right) right = dfs(root->right);
		if (left && right && root->val == 0) return true;
		if (left) root->left = NULL;
		if (right) root->right = NULL;
		return false;
	}

    TreeNode* pruneTree(TreeNode* root) {
    	if (!root) return root;
    	if (dfs(root)) return NULL;
    	return root;
    }
};
```