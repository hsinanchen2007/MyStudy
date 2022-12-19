**一、递归算法：**

```c++ []
int maxDepth(TreeNode* root) {
    if (!root)
         return 0;
    else
         return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```

**二、迭代算法**

```c++ []
int maxDepth(TreeNode* root) {
		stack<pair<TreeNode*, int>> stack;
		int depth = 0;
		if (root) stack.push(pair<TreeNode*,int>(root,1));
		while (!stack.empty()) {
			pair<TreeNode*, int> curr = stack.top();
			stack.pop();
			TreeNode* curr_node = curr.first;
			int curr_dep = curr.second;
			if (curr_node) {
				depth = max(depth, curr_dep);
				stack.push(pair<TreeNode*, int>(curr_node->left, curr_dep + 1));
				stack.push(pair<TreeNode*, int>(curr_node->right,curr_dep + 1));
			}
		}
		return depth;
	}
```

