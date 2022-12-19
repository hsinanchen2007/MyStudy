先把右半边的树中的每个节点的两个叉左右调换,再调用100题的解法,判断左半边和右半边是不是同样的树.
```cpp
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		if (root->left == nullptr and root->right == nullptr) return true;
        if (root->left == nullptr or root->right == nullptr) return false;
		mySwap(root->right);
		return isSameTree(root->left, root->right);

	}
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr and q == nullptr) return true;
		if (p == nullptr or q == nullptr) return false;
		if (p->val == q->val and isSameTree(p->right, q->right) and isSameTree(p->left, q->left))
			return true;
		else
			return false;
	}
	void mySwap(TreeNode* root) {
		swap(root->left, root->right);
		if (root->left != nullptr) mySwap(root->left);
		if (root->right != nullptr) mySwap(root->right);
	}
};
```
