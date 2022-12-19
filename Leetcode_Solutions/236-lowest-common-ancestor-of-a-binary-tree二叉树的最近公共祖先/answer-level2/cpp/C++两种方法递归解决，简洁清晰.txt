方法一：判断p和q是否在左右子树中，树自顶向下遍历过程中，不断判断，并根据此结果得到LCA
时间复杂度O(n^2)，空间复杂度O(n^2)
```cpp
class Solution 
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		/*p和q都在左子树中*/
		if (isInThisTree(root->left, p) && isInThisTree(root->left, q))
		{
			return lowestCommonAncestor(root->left, p, q);
		}
		/*p和q都在右子树中*/
		if (isInThisTree(root->right, p) && isInThisTree(root->right, q))
		{
			return lowestCommonAncestor(root->right, p, q);
		}
		/*p或q本来就是root节点，或者p和q分别在root左右*/
		return root;
	}

	/*判断某个节点是否在此树中*/
	bool isInThisTree(TreeNode* root, TreeNode* m)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->val == m->val)
		{
			return true;
		}
		return isInThisTree(root->left, m) || isInThisTree(root->right, m);
	}
};
```
方法二：一次遍历，在根节点左右子树中分别搜索p和q，找到则返回节点。根据左右子树搜索结果进行分类讨论，返回LCA
时间复杂度O(n)，空间复杂度O(n)
```cpp
class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if ((root == nullptr) || (root->val == p->val) || (root->val == q->val))
		{
			return root;
		}
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		
		/*p和q都在左子树中*/
		if ((left != nullptr) && (right == nullptr))
		{
			return left;
		}
		/*p和q都在右子树中*/
		if ((left == nullptr) && (right != nullptr))
		{
			return right;
		}
		/*p和q分别在左右子树中*/
		if ((left != nullptr) && (right != nullptr))
		{
			return root;
		}
        return nullptr;
	}
};
```