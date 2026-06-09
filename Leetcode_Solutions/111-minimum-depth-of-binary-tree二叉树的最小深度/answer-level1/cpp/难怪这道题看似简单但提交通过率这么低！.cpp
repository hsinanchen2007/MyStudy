很多人可能跟我一样，第一反应想到了求二叉树最大深度的那道题目，然后直接将max改成min，如下：

**错误示例：**

```
class Solution 
{
public:
	int minDepth(TreeNode* root) 
	{
		if (root == nullptr)
		{
			return 0;
		}
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};
```
然而按照这个判据，那么一棵只有单一子树的树，其最小深度为1，显然错误

**正确示例：**
```cpp
class Solution 
{
public:
	int minDepth(TreeNode* root) 
	{
		if (root == nullptr)
		{
			return 0;
		}
		if (root->left == nullptr)
		{
			return minDepth(root->right) + 1;
		}
		if (root->right == nullptr)
		{
			return minDepth(root->left) + 1;
		}
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};
```