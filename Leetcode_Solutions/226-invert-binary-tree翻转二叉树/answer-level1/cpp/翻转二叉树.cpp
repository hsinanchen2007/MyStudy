**一、递归**
树形结构天然适合递归，因为树的定义就是递归定义的。本函数定义为`TreeNode* invertTree(TreeNode* root)`。说明：以root为根的二叉树翻转后返回根，那么对以左孩子为根的树和以右孩子为根的树同样适用，注意：**对左孩子为根的树处理前需要保存右指针**。
```
TreeNode* invertTree(TreeNode* root) {
	if (!root || (!root->left && !root->right)) return root; //空树和只有1个结点的树
	TreeNode *temp = root->right;
	root->right = invertTree(root->left); //先处理左子树部分
	root->left = invertTree(temp); //再处理右子树部分
	return root; //返回根结点
}
```
从代码中可以看到，其实质是先序遍历（DFS）。
**二、循环**
利用一个队列实现，算法如下：
1、根结点入队。
2、每次处理1层，如果左右孩子不全为空，交换左右指针，将非空的左右孩子入队。
3、队列为空，循环结束。
```
TreeNode* invertTree(TreeNode* root) { //函数功能：反转以root为根的二叉树
	if (!root) return root;
	queue<TreeNode*> que; que.push(root);
	while (!que.empty()) {
		int n = que.size();
		for (int i = 0; i < n; ++i) {
			TreeNode *node = que.front(); que.pop();
			if (!node->left && !node->right) continue; //对叶子不做处理
			//交换左右指针
			TreeNode *temp = node->left;
			node->left = node->right;
			node->right = temp;
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
	}
	return root;
}
```