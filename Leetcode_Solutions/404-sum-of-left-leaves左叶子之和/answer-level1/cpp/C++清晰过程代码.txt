主要思路是，判断当前节点的左子树是否为左叶节点
详细过程见代码注释
```cpp
class Solution
{
public:
	int sum = 0;
	int sumOfLeftLeaves(TreeNode* root)
	{
		/*根节点为nullptr或者根节点为叶节点*/
		if (root == nullptr || isLeaf(root))
		{
			return sum;
		}
		/*左子树为叶节点*/
		if (root->left != nullptr && isLeaf(root->left))
		{
			sum += root->left->val;
			sum = sumOfLeftLeaves(root->right);
		}
		else
		{
			sum = sumOfLeftLeaves(root->left);
			sum = sumOfLeftLeaves(root->right);
		}
		return sum;
	}
	/*判断节点是否为叶节点*/
	bool isLeaf(TreeNode* root)
	{
		return (root != nullptr && root->left == nullptr && root->right == nullptr) ? true : false;
	}
};
```