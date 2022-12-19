主函数递归：判断是否调用子结构判断函数
子函数递归：前序遍历判断b是否为a的子结构
```
class Solution
{
	bool Dfs(TreeNode* a, TreeNode* b) {
		if (!b) {
			return true;
		}
		if (!a || a->val != b->val) {
			return false;
		}
		return Dfs(a->left, b->left) && Dfs(a->right, b->right);
	}
public:
	bool isSubStructure(TreeNode* a, TreeNode* b) {
		if (!a || !b) {
			return false;
		}
		if (a->val == b->val && Dfs(a, b)) {
			return true;
		}
		return isSubStructure(a->left, b) || isSubStructure(a->right, b);
	}
};
```
