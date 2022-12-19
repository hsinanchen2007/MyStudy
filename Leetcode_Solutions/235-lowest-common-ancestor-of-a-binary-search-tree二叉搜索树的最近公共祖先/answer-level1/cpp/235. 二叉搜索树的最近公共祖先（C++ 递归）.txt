# 235. 二叉搜索树的最近公共祖先
**思路：**
- 题目函数传入了三个二叉搜索树节点，我们分别可以得到三个二叉搜索树节点的值。
- 根据二叉搜索树的特性，左子树节点值永远小于根节点值，右子树节点值永远大于根节点值。
    1. 可知两个节点的公共组件节点值一定大于等于两个节点的小值，小于等于两个节点的大值。
    2. 如果根节点值大于两节点值，那么把根节点设为此根节点的右子节点，继续上述操作；
    3. 如果根节点值小于两节点值，那么把根节点设为此根节点的左子节点，继续上述操作；
**完整代码：**
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if(root != NULL)
		{
			int min_num = min(p->val,q->val);
			int max_num = max(p->val,q->val);
			if((root->val >= min_num) && (root->val <= max_num))
			{
				return root;
			}
			else
			{
				if(root->val > max_num)
				{
					return lowestCommonAncestor(root->left,p,q);
				}
				else if(root->val < min_num)
				{
					return lowestCommonAncestor(root->right,p,q);
				}
			}
		}
		return NULL;
    }
};
```
