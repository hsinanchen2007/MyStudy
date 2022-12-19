![image.png](https://pic.leetcode-cn.com/ec3d93543045778a7a6781a6a0e9f8c7c8cf6da74c46d69459d197942759bab0-image.png)
1. 思路：求满足所有条件的路径，并把它们记录下来。我们可以很容易想到采用 DFS 思想可以解决问题，问题来了，采用何种遍历方式呢？先序、中序、还是后序。当然，如果是递归去做的话，没有什么区别，我们在这里谈论的是**如何用循环实现**。
2. 在回味一下先序、中序以及后序以循环模拟递归的大致思路后，我们可以很明显地感受到，在后序中，先处理左子树、而后处理右子树，最后处理根结点。换句话说，处理完右子树的时候，**根结点仍然是在栈中的**。
3. 我们约定，**入栈将当前结点值加入到路径中，出栈将当前结点值从路径中除去**，这恰好是一个互逆操作。递归函数运行流程分两个部分，1）不断深入；2）**不断回退（回溯）**。那满足何种条件回溯呢？对于一棵二叉树，如果已经访问根结点了，就可以回溯了。更多的细节，请结合代码注释理解，也可以在评论区留言，帮助我们查漏补缺。
```
vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> ans; vector<int> curr; //分别记录所有满足条件的路径、一条满足条件的路径
	if (!root) return ans;
	stack<TreeNode*> stk; TreeNode *prev = nullptr;
	while (root || !stk.empty()) { //模拟系统递归栈
		while (root) {
			stk.push(root); sum -= root->val; curr.push_back(root->val); //入栈、更新剩余和、路径
			root = root->left;
		}//递归访问左结点

		root = stk.top(); //不能再左了，取得右拐点（根结点）
		if (!root->left && !root->right && (sum == 0)) { //条件：是叶子结点且剩余和为0
			ans.push_back(curr); //满足条件，保存路径
		}

		if (!root->right || root->right == prev) { //右结点不存在或已经访问 回溯
			stk.pop(); sum += root->val; curr.pop_back(); //出栈、更新剩余和、路径
			prev = root; //标记已访问
			root = nullptr; //用于回溯到上一级
		}
		else { //递归访问右结点
			root = root->right;
		}
	}
	return ans;
}
```