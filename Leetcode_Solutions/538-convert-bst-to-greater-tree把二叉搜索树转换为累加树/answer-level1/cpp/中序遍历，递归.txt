由于是二叉搜索树，又要从大加到小，所以采用中序遍历，先右子树，再根节点，再左子树。
代码中函数`accumulate_Tree`的形参pre为计算该子树前已经累加到的值，返回值为该子树累加后的值。（其实可以直接引用pre作为累加值的记录，而不用另外添加返回值）
```C++ []
class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {
		accumulate_Tree(0, root);
		return root;
	}
	int accumulate_Tree(int pre, TreeNode* root) {
		if (!root)
			return pre;
		int cur = accumulate_Tree(pre, root->right);
		cur += root->val;
		root->val = cur;
		return accumulate_Tree(cur, root->left);
	}
};
```
