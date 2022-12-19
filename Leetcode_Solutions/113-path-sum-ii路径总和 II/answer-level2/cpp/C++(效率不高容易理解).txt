```
class Solution {
public:
	vector<int> tmp;
	vector<vector<int>> result;
	vector<vector<int>> path(TreeNode* root, int sum, vector<int> tmp) {
		if (root == NULL)
			return{};
		tmp.push_back(root->val);
		if (root->val == sum && root->left == NULL && root->right == NULL) {
			result.push_back(tmp);
			return result;
		}
		else if (root->left == NULL && root->right == NULL) {
			return result;
		}
		path(root->left, sum - root->val, tmp);
		path(root->right, sum - root->val, tmp);
		return result;
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result = path(root, sum, tmp);
		return result;
	}
};
```
