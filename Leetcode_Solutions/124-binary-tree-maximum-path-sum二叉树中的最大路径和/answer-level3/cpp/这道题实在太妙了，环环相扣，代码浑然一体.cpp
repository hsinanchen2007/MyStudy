这种题解法只能记下来，自己根本想不出来这么好的方法
难点在于：
1. 如何实现去除某些累赘节点？代码中是从叶节点开始，路径和小于0则丢弃
2. 如何转换出所求值？代码中先分别计算出以左右节点为端点的最大路径和，再加上根节点的值
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
class Solution
{
public:
	/*返回值为，从根节点开始的最大路径和*/
	int backtrack(TreeNode* root, int& result)
	{
		if (!root)
		{
			return 0;
		}
		/*一旦路径和小于0，就置为0，这样就实现了去除一些节点*/
		int left = max(backtrack(root->left, result), 0);
		int right = max(backtrack(root->right, result), 0);
		/*左+根+右实际上就包含了所有路径可能*/
		result = max(result, root->val + left + right);
		return root->val + max(left, right);
	}
	int maxPathSum(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		int result = INT_MIN;
		backtrack(root, result);
		return result;
	}
};
```