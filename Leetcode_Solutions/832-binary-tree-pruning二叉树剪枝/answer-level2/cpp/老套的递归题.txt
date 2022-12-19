乍一看题目，要求所有子树都不包含1，很容易想到递归思路：

1. 假如节点本身是叶子节点，而且值为0，这个节点就要被删除（这也是递归出口）
2. 假如左子树满足1的条件，删除左子树，右子树满足1的条件，删除右子树
3. 经过2以后根节点满足1的条件，就删除根节点，否则返回根节点，表示这棵树不用全删除（子树包含值为1的节点）
```
class Solution {
public:
	TreeNode* pruneTree(TreeNode* root) {
		if (!root) return NULL;
		root->left = pruneTree(root->left);
		root->right = pruneTree(root->right);
		if (!root->left && !root->right && root->val == 0) return NULL;
		else return root;
	}
};
```