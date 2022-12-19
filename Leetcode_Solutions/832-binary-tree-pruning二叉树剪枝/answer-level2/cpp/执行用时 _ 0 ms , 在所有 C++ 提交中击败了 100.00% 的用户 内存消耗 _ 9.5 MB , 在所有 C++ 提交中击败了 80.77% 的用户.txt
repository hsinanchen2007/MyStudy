### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	bool isAll(TreeNode* root) {
		if (root==NULL) {
			return false;
		}
		if (root->val != 0) {
			return true;
		}
		bool b1=isAll(root->left);
		if (b1 == true) return true;
		bool b2 = isAll(root->right);
		if (b2 == true) return true;
		return false;
	}
	bool dfs(TreeNode* root) {
		if (root == NULL) {
			return true;
		}
		if (isAll(root)!=true) {
			return false;
		}
		
		bool b1 = dfs(root->left);
		if (b1==false) {
			root->left = NULL;
		}
		bool b2 = dfs(root->right);
		if (b2 == false) {
			root->right = NULL;
		}
		return true;
	}

	TreeNode* pruneTree(TreeNode* root) {
		dfs(root);
		return root;
	}
};

```