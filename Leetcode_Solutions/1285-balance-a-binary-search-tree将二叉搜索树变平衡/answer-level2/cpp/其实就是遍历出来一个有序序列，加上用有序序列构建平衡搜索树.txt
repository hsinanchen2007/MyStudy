### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	vector<int> vals;
	void inorder(TreeNode* root)
	{
		if (!root) return;
		else
		{
			inorder(root->left);
			vals.push_back(root->val);
			inorder(root->right);
		}
	}

	TreeNode* build(int l, int r)
	{
		if (l > r) return nullptr;
		else
		{
			int m = l + (r-l) / 2;
			TreeNode * root = new TreeNode(vals[m]);
			root->left = build(l, m - 1);
			root->right = build(m + 1, r);
			return root;
		}
	}
	TreeNode* balanceBST(TreeNode* root) {
		inorder(root);
		return build(0, vals.size() - 1);


	}
};
```