# 226. 翻转二叉树
**思路：**
- 想要翻转一棵二叉树，归结到这颗二叉树每个节点的操作为交换节点左右子树位置。
- 从而可以吧翻转二叉树，归结到每个节点中处理，可以采用递归的方式：
    1. 首先在当前遍历到节点不为空的情况下，翻转二叉树节点中的左右子树指针。
    2. 然后以相同方式操作左右子树（递归传入左右子树根节点）。

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
    TreeNode* invertTree(TreeNode* root) {
		if(root != NULL)
		{
			//翻转
			TreeNode* temp = root->left;
			root->left  = root->right;
			root->right = temp;
			
			//递归
			invertTree(root->left);
			invertTree(root->right);
		}
        return root;
    }
};
```
