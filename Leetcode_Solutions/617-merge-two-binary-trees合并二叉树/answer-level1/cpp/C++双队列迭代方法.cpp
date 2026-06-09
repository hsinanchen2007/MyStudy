和官方利用一个栈是基本一致的方法，只不过用了队列就是层次遍历，两个队列也可以合并成一个队列
空间O(m+n)，时间O(max(m, n))
```
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr) return t2;
		if (t2 == nullptr) return t1;
		queue<TreeNode*> que1 = queue<TreeNode*>();
		queue<TreeNode*> que2 = queue<TreeNode*>();
		que1.push(t1);
		que2.push(t2);
		TreeNode* tem1 = nullptr;
		TreeNode* tem2 = nullptr;
		while (!que1.empty() && !que2.empty()) {
			tem1 = que1.front();
			que1.pop();
			tem2 = que2.front();
			que2.pop();
			bool flag = tem2 == nullptr;
			tem1->val = flag ? tem1->val : tem1->val + tem2->val;
			if (tem1->left == nullptr) {
				tem1->left = flag ? nullptr : tem2->left;
			}
			else {
				que1.push(tem1->left);
				que2.push(flag ? nullptr : tem2->left);
			}
			if (tem1->right == nullptr) {
				tem1->right = flag ? nullptr : tem2->right;
			}
			else {
				que1.push(tem1->right);
				que2.push(flag ? nullptr : tem2->right);
			}
		}
		return t1;
	}
```
