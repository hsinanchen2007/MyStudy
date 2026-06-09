**方法一：递归**
递归这种东西，真的是想通以后就觉得非常easy。翻转二叉树就是把每个节点的左右节点互换。当然中间要考虑节点是否为NULL，对于NULL节点就不需要交换其左右节点了，对于递归来说，就是不需要递归，对于迭代来说，就是不需要压栈了。
```
class Solution {
	void invert(TreeNode* root){
		TreeNode* tmp;
		tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		if (root->left != NULL) invert(root->left);
		if (root->right != NULL) invert(root->right);
	}
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root != NULL)
			invert(root);
		return root;
	}
};
```
**方法二：迭代**
将需要交换其左右节点的节点压栈，交换完毕后出栈，直到栈为空。
```
class Solution {

public:
	TreeNode* invertTree(TreeNode* root) {
		stack<TreeNode*>s;
		if (root == NULL) return root;
		TreeNode* cur = root;
		s.push(cur);
		while (!s.empty()){
			TreeNode* t = s.top();
			TreeNode* tmp = t->left;
			t->left = t->right;
			t->right = tmp;
			s.pop();//交换左右两个节点
			if (t->left != NULL) s.push(t->left);
			if (t->right != NULL) s.push(t->right);
		}
		return root;
	}
};
```
