从上到下的层次顺序，适合前序遍历。
具体到每个节点：
（1）当前节点与p或q相同，说明共同节点是p或q
（2）不满足（1）则分别遍历左右子树。如果在左子树，那么从右子树返回的结果为空；如果在右子树，那么从左子树返回的结果为空。如果是当前节点，则左右子树返回的结果均不为空。
```
class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || p == root || q == root) {
			return root;
		}
		TreeNode* l = lowestCommonAncestor(root->left, p, q);
		TreeNode* r = lowestCommonAncestor(root->right, p, q);
		if (l && r) {
			return root;
		}
		return (r) ? r : l;
	}
};
```
