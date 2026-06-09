**一、问题分析**
我并不是仅仅在谈论本道题，二叉树的四种操作（先序、中序、后序、层序），要十分熟练并懂得具体问题具体分析。虽然说是有4种，但是往大了分——只有两种（DFS和BFS）。好的，现在开始讲解如何结合四种基本操作来解题。
**二、先序遍历**
对于一棵树来说，最重要的是根结点，它有两个属性：1）**值属性**，自带一个val域；2）**代表属性**，它是本棵树的代表。因而，思考树型结构相关的问题，**最忌讳的就是递归分析**，也即一定去模拟递归是如何进行的。脑子里能装几个栈呢？递归层次一深，很容易就写错了。为了根除不好的思维方式，我们采用层次分析。
先序遍历，大层次上是根左右，那么左子树部分是什么样的呢？右子树部分是什么样的呢？要说的是，不去管它，只需要知道先处理根，再处理左子树部分，最后处理右子树部分。左右子树和最大的树结构一样，只是规模小了一点。
算法设计：
在先序遍历的过程中，如果判定某个结点是左叶子，就将值累加。
**2.1 循环版本**
```
int sumOfLeftLeaves(TreeNode *root) {
	if (!root) return 0;
	int sum = 0;
	stack<TreeNode*> stk;
	stk.push(root);
	while (!stk.empty()) {
		TreeNode *node = stk.top(); stk.pop();
		if (node->left && !node->left->left && !node->left->right) { //左叶子
			sum += node->left->val;
		}
		if (node->right) stk.push(node->right);
		if (node->left) stk.push(node->left);
	} //先序遍历-循环实现
	return sum;
}
```
**2.2 递归版本**
```
int sumOfLeftLeaves(TreeNode* root) {
	//缩小问题规模 左子树左叶子数+右子树左叶子数
	if (!root) return 0;
	return helper(root->left, root) + helper(root->right, root);
}
int helper(TreeNode *node, TreeNode *root) {
	if (!node) return 0;
	if ((!node->left && !node->right) && root->left == node) //左叶子
		return node->val;
	return helper(node->left, node) + helper(node->right, node);
} //先序遍历-根左右
```
**三、层序遍历**
```
int sumOfLeftLeaves(TreeNode *root) {
	if (!root) return 0;
	int sum = 0;
	queue<TreeNode*> que; que.push(root);
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; ++i) {
			TreeNode *node = que.front(); que.pop();
			if (node->left && !node->left->left && !node->left->right) {
				sum += node->left->val;
			}
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
	}
	return sum;
} //层序遍历
```