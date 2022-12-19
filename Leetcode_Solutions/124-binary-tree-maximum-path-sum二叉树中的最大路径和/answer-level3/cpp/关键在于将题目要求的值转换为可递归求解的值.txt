最初我的想法为主函数用来遍历所有根节点，递归函数用来求从以根节点为起始点往下的最大路径和
这样的思路也是正确的，但是会有很多重复的计算，因为每次都要从根节点遍历到叶节点
代码如下：
```cpp
class Solution
{
public:
	int res = INT_MIN;
	int getSumToLeaf(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		int left = max(getSumToLeaf(root->left), 0);
		int right = max(getSumToLeaf(root->right), 0);
		int sum = max(left, right);
		return max(root->val + sum, 0);
	}
	int maxPathSum(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		int curr = root->val + getSumToLeaf(root->left) + getSumToLeaf(root->right);
		res = max(curr, res);
		maxPathSum(root->left);
		maxPathSum(root->right);
		return res;
	}
};
```
之后将res的计算融合到了递归函数中。递归函数的返回值仍然是根节点往下的最大路径和，但是在往下遍历的过程中，就顺便将res计算了出来
```cpp
class Solution
{
public:
	int res = INT_MIN;
	/*计算以根节点为起始点往下的最大路径和*/
	int getSumToLeaf(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		int left = max(getSumToLeaf(root->left), 0);
		int right = max(getSumToLeaf(root->right), 0);
		/*每一次访问到根节点时，顺便计算了题目要求的路径和
		此函数名义为计算从根节点起始的最大路径和，实际是
		为了计算题目要求的值*/
		res = max(res, root->val + left + right);
		/*返回此递归函数的要求值*/
		return root->val + max(left, right);
	}
	int maxPathSum(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		/*实际上最终并没有用到递归函数的返回值*/
		getSumToLeaf(root);
		return res;
	}
};
```