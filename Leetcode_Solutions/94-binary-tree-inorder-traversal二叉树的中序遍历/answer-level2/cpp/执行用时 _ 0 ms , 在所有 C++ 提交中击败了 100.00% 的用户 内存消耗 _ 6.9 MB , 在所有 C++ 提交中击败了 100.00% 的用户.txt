### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	void inOrder(TreeNode* root,vector<int> &res) {
		if (root==NULL) {
			return;
		}
		inOrder(root->left, res);
		res.push_back(root->val);
		inOrder(root->right, res);
		
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inOrder(root, res);
		return res;
	}
};
```