莫里斯算法的精髓之处在于把一个搜索树变成了了一个线性树
官方的莫里斯算法有一个最大的问题就是破坏了树的结构
也就是找到根节点的前驱节点后 把根节点的左节点变成空的 把前驱节点的右节点变成了根节点
完完全全的变成了一个线性树。。
那么怎么在不破坏原有结构的基础上做一次遍历呢？或者说 我们在破坏了结构遍历后 怎么恢复原结构呢
原寻找前驱节点的条件即 根节点的左子树的最右子树为空
假设我们找到前驱节点后 不动根节点 只将前驱节点的右节点连接到根节点
那么这就形成了一个环 遍历一遍以后 回到了根节点
根节点求前驱节点麻烦就大了 因为这个前驱节点条件来看 他是一个环
问题反倒简单了 只需要这个时候加上一个另一个条件 即前驱节点的右节点==根节点
我们就找到了这个环链接的地方 
再把它断开就好了~
```
vector<int> inorderTraversal2(TreeNode* root) {
	vector<int> res;
	while (root != nullptr) {
		if (root->left == nullptr) {				//如果左树是空的
			res.push_back(root->val);
			root = root->right;
		}
		else {													//如果左树不是空的
			TreeNode* pre;
			pre = root->left;
			while (pre->right != nullptr && pre->right != root)
				pre = pre->right;
			if (pre->right == nullptr) {
				pre->right = root;
				root = root->left;
			}
			else {
				pre->right = nullptr;
				res.push_back(root->val);
				root = root->right;
			}
		}
	}
	return res;
}
```

