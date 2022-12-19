本来不想写的，已有题解太多，但是试了几次和测试的预期结果（参考答案）完全一致。还是分享一下吧。
```
class Solution {
public:
	vector<int> Store;
	int end = 0;
	TreeNode* balanceBST(TreeNode* root) {
		dfs(root);
		TreeNode* newTree = CreateTree(end);
		return newTree;
	}
	void dfs(TreeNode* root) {
		if (root == NULL) return;
		dfs(root->left);
		Store.push_back(root->val);
		++end;
		dfs(root->right);
	}
	TreeNode* CreateTree(int n) {//构造的同时逆向中序遍历
		if (n == 0) return NULL;
		TreeNode* root = new TreeNode(-1);
		root->right = CreateTree(n >> 1);
		root->val = Store[--end];
		root->left = CreateTree((n - 1) >> 1);
		return root;
	}
};
```

