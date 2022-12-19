```
class Solution
{
private:
	int Dfs(TreeNode* root) {
		if (!res || !root) {
			return 0;
		}
		int l = Dfs(root->left);
		int r = Dfs(root->right);
		if (abs(l - r) > 1) {
			res = false;
			return 0;
		}
		return max(l, r) + 1;
	}
	bool res;
public:
	bool isBalanced(TreeNode* root) {
		res = true;
		Dfs(root);
		return res;
	}
};
```
