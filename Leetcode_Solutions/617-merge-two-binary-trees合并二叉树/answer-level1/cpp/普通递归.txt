如果某棵树为空，则返回另一颗树。（这时如果另一颗树也为空，则正好返回空）
如果两颗树都不为空，则新建一个节点，节点值为`t1->val + t2->val`，左子树和右子树分别为t1和t2的左右子树调用此函数的返回值。
```C++ []
class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		TreeNode* res = NULL;
		if (!t1)
			return t2;
		if (!t2)
			return t1;

		res = new TreeNode(0);
		res->val += t1->val;
		res->val += t2->val;
		res->left = mergeTrees(t1->left, t2->left);
		res->right = mergeTrees(t1->right, t2->right);
		return res;
	}
};
```
