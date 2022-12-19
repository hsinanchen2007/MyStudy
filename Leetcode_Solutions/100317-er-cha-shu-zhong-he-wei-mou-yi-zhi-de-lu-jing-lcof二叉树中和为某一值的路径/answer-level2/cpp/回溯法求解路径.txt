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
	vector<vector<int>> v;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int>vv;
		if (!root)return v;
		TreePath(root, vv, sum);
		return v;
	}
	void TreePath(TreeNode* root,vector<int>& vv,int sum) {
		sum -= root->val;
		vv.push_back(root->val);
		if (root->left == nullptr&&root->right==nullptr&&sum== 0) {
			v.push_back(vv);
			return;
		}
		if (root->left == nullptr&&root->right == nullptr)return;
		if (root->right != nullptr) {
			TreePath(root->right, vv, sum);
			vv.pop_back();
		}
		if (root->left != nullptr) {
			TreePath(root->left, vv, sum);
			vv.pop_back();
		}
	}
};
```