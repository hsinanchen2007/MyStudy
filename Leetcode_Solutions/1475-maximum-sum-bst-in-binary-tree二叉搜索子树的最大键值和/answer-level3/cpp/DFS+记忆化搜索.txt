### 解题思路
双周赛的时候超时了。。。。

首先明确子树的概念，以某个节点为根的树；本题求的是二叉搜索子树，所以那棵树必须满足两个条件：二叉搜索树+达叶子节点。
以例一为例：
![sample_1_1709.png](https://pic.leetcode-cn.com/18295884fcefa2eb88d5bc2167f259a2ed1e2f400c3b0d7914ddbf7c06e14c69-sample_1_1709.png)

所以首先判断以1为根节点的数是否为二叉树（这个很简单，遍历即可）；发现并不是二叉树，所以根1不可能在满足条件的二叉搜索树里面，直接丢弃即可；
其次，遍历左子树和右子树；在遍历到根为3的时候，发现它为一课二叉搜索树，所以需要找到以它为根的树及其子树的节点最大值；
如果普通的递归，先找左子树的和，再找右子树的和，然后加上根节点，得到当前树的和；然后在左右遍历，找到这一系列中的最大值，很暴力，周赛就是这样超时的。。。。。
可以发现，这个过程中子树被访问了很多次。。。

其实在求解左子树+右子树和的时候，我们可以传一个引用变量，每次求得以当前节点为根的val和之后，可以同引用变量比较，取最大值，这样遍历完之后，子树的最大值找到了，同时也找到了左子树+右子树的和，然后同当前树的和进行比对，就找到了最大值。

### 代码

```cpp
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
		bool IsBST(TreeNode* root) {
			if (root == NULL) {
				return true;
			}
			if (root->left != NULL && root->left->val >= root->val) {
				return false;
			}
			if (root->right != NULL && root->right->val <= root->val) {
				return false;
			}
			return (IsBST(root->right) && IsBST(root->left));
		}
		int GetChildTreeSum(TreeNode* root, int& maxSum)
		{
			if (root == NULL) {
				return 0;
			}
			int childSum = GetChildTreeSum(root->left, maxSum) + GetChildTreeSum(root->right, maxSum) + root->val;
			maxSum = max(maxSum, childSum);
			return childSum;
		}
		int GetMaxSumBST(TreeNode* root, int& maxSum) 
		{
			if (root == NULL) {
				return 0;
			}
			if (IsBST(root)) {
				int childSum = GetChildTreeSum(root->left, maxSum) + GetChildTreeSum(root->right, maxSum) + root->val;
				maxSum = max(childSum, maxSum);
				return maxSum;
			}
			return max(maxSumBST(root->right), maxSumBST(root->left));
		}
		int maxSumBST(TreeNode* root) {
			if (root == NULL) {
				return 0;
			}
			int maxSum = 0;
			return GetMaxSumBST(root, maxSum);
		}
	};
```