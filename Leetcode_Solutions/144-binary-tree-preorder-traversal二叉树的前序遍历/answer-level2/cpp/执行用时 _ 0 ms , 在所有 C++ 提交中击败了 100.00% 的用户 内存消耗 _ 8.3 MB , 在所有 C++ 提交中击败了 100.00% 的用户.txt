### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	void dfs(vector<int> &res,TreeNode* root) {
		if (root == NULL) { return; }
		res.push_back(root->val);
		dfs(res, root->left);
		dfs(res, root->right);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		dfs(res, root);
		return res;
	}
};
```