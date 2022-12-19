#### 经典简明的递归问题
二叉树的的深度等于左/右子树的深度的较大值加1。即`maxDepth(root)=Max(maxDepth(root->left),maxDepth(root->right))+1`
该递归过程又是经典的DFS深度优先搜索过程。
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};
```
常规上来说，大部分的递归都可以使用堆栈的入栈出栈操作来模拟；另外一种遍历二叉树的方式BFS，则是通过队列的方式来实现。详见
[Maximum Depth of Binary Tree - LeetCode官方题解](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/er-cha-shu-de-zui-da-shen-du-by-leetcode/)

我果真不适合写题解，写文章啊！