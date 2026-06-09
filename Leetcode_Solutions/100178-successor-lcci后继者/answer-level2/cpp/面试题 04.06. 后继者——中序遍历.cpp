本质是找到比给定节点大的下一个节点，由于是二叉搜索树，所以通过节点比较可以快速找到对应节点。
（1）当前节点小于等于给定节点，说明结果一定在右子树
（2）当前节点大于给定节点，说明结果一定在左子树。此时又分为两种情况：若返回结果为空，说明当前节点是最终结果；否则直接返回左子树得到的结果。
```
class Solution
{
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
	{
		if (!root) {
			return nullptr;
		}
		if (root->val <= p->val) {
			return inorderSuccessor(root->right, p);
		} else {
			TreeNode* res = inorderSuccessor(root->left, p);
			if (!res) {
				return root;
			} else {
				return res;
			}
		}

		return nullptr;
	}
};
```
