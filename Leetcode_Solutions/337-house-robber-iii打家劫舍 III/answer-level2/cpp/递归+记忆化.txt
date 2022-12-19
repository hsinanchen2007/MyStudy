第一题 [我的题解](https://leetcode-cn.com/problems/house-robber/solution/dong-tai-gui-hua-by-njucly/)
第二题 [我的题解](https://leetcode-cn.com/problems/house-robber-ii/solution/dong-tai-gui-hua-he-di-yi-ti-chai-bu-duo-zhi-shi-y/)
对代码中转移方程不懂的可以先看上两题题解。

这题变成二叉树后比前两道难了一些。
关键在于如果要用动态规划，则要重新构建一颗一模一样的二叉树作为dp数组的存储，然后还要按叶节点向上到根节点的顺序计算dp数组的值。这样的遍历方式我是没见过，感觉也挺难写。

所以只能改成递归的方式，但递归写完发现超时了。
没有办法，只能查了一下曾经听过的所谓记忆化的方法：记忆化就是将递归过程中算过的函数用一个结构保存起来，以后要再算的时候就直接返回保存好的值。在C++中用unordered_map（即hashmap）可以作为普遍的保存结构，key为问题所需要的参数，即递归函数的参数，value为递归函数的返回值。

这种递归+记忆化的方法相比于只递归，少做了重复计算，减小了运行时间。
这种递归+记忆化的方法相比于动态规划，相当于将动态规划的数组改成了用map来保存，从运行时间上来讲应该和动态规划没什么差距，但从空间消耗上来讲毕竟用了递归，递归栈所用的空间还是比动态规划多用的。

那么这题为什么不用动态规划呢？动态规划要从小问题算到大问题，对于二叉树，最小的问题是叶节点，再大一点是叶节点的父节点作为根节点的子树，最大的是根节点，这种从小到大的访问顺序我写不来，所以就不用了。

又去看了一下别人的题解，默认排序第一的题解（[链接在这](https://leetcode-cn.com/problems/house-robber-iii/solution/san-chong-fang-fa-jie-jue-shu-xing-dong-tai-gui-hu/)）里的第三种方法用了递归，但是将每个节点的值状态分成了不偷和偷两种，这样递归可以值用到它子节点的值。我本来想当然的以为递归都是有重复子问题的（一看我就学习没学好），看了题解后发现他这个方法耗时更少了，所以又仔细想了想，好像确实没有算过重复的问题，这样看来也是个减小运行时间的好方法，当然了递归栈导致的空间消耗还是存在的，当树很大时肯定不如正宗的动态规划。

```C++ []
class Solution {
public:
	unordered_map<TreeNode*, int> m;
	int rob(TreeNode* root) {
		int res = helper(root);
		return res;
	}

	int helper(TreeNode* root) {
		//返回不抢root和抢root的能抢到的最大值
		if (!root)
			return 0;
		auto it = m.find(root);
		if (it != m.end()) {
			return it->second;
		}

		int res = 0;
		//0表示不抢root，1表示抢root
		int root_0 = helper(root->left) + helper(root->right);
		int root_1 = root->val;
		if (root->left)
			root_1 += helper(root->left->left) + helper(root->left->right);
		if (root->right)
			root_1 += helper(root->right->left) + helper(root->right->right);
		res = max(root_0, root_1);
		m.insert({ root,res });
		return res;
	}
};
```
