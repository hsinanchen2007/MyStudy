因为是二叉搜索树，根节点值大于左子树值，小于右子树值，所以简单了很多

```cpp
class Solution 
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		if ((p->val < root->val) && (q->val < root->val))
		{
			return lowestCommonAncestor(root->left, p, q);
		}
		if ((p->val > root->val) && (q->val > root->val))
		{
			return lowestCommonAncestor(root->right, p, q);
		}
		return root;
	}
};
```