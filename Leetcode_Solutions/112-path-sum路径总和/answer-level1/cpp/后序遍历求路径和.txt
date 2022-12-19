写在前面：感谢楼主[@windliang](/u/windliang/)，在你的文章[详细通俗的思路分析，多解法](https://leetcode-cn.com/problems/path-sum/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-26/)启发到我了。读完你的分析，正好解开了我的疑惑。
- 如果使用DFS（深度优先遍历）来求路径和的话，我们知道有三种遍历方式（先序、中序、后序），当我们用循环实现的时候，带来一个难以解决的问题，如何判断特定的路径和是否为题目要求的？很多解法是基于中序遍历的循环实现，不可避免地把**路径长度也放到另一个栈**中，实时比较（也有把指针和路径长度打包成一个pair放入一个栈中，大同小异）。有没有一种解法，将路径长度用一个变量保存？看完楼主[@windliang](/u/windliang/)的思路，我也想通可以用后序遍历。
- sum是题中要求的路径和，我也可以用补充的思维将其想象成剩余和，每次遍历一个结点，就减去结点值；每次回退一个结点，就加上结点值；最后判断计算得到的路径和是否为0来判断。
- 易错点
```
if (!root->right && (sum == 0)) { //判断路径是否满足条件
	return true;
}
```
![image.png](https://pic.leetcode-cn.com/3fd4b6eee8a8bb75a0fde9b34289b354622f117b8002a81f6c94d612ff2dd8f1-image.png)
上面是原先的判断条件，让我颇为困惑的是，测试用例大部分正确，最终我明白了。
![image.png](https://pic.leetcode-cn.com/c0230137af813010aa8c1f170d8c3c89354fd16c671cb23658b0dd1acbb1971d-image.png)
在图中，如果路径和要求为5的话，会给出true的判断，仔细揣摩，之下，我想当然地认为root一定没有左孩子，当然我想错了。之后我将代码改成了现在的样子。
```
bool hasPathSum(TreeNode* root, int sum) { //参数1-二叉树的根；参数2-剩余和
	if (!root) return false;
	stack<TreeNode*> stk;
	TreeNode *prev = nullptr;
	while (root || !stk.empty()) {
		while (root) {
			stk.push(root); sum -= root->val; //入栈后更新剩余和
			root = root->left; //递归左子树
		}
		root = stk.top(); //取得右拐点（根结点）
		if (!root->left && !root->right && (sum == 0)) { //判断路径是否满足条件
			return true;
		}
		if (!root->right || root->right == prev) { //右结点不存在或者，右结点已访问
			stk.pop(); sum += root->val; //出栈后更新剩余和
			prev = root; //标记在后序遍历序列已访问
			root = nullptr; //置空，用于回溯
		}
		else {
			root = root->right; //访问右结点
		}
	}//模拟递归栈
	return false;
}
```


