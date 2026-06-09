**一、思路**
**1.1 递归**
**二叉树由于自身是递归定义**的，所以天然就具有递归结构。给定一棵二叉树，如果是空树或者只含1个结点，规定为单值；否则比较其左子树所有结点、右子树所有结点是否分别全都等于根结点的值；到了这一步，问题已经发生了转变——问题结构不变，而问题规模变小，所以我们可以很快提出递归算法：
1、如果是空树或者只含1个结点，判定为单值二叉树；
2、判定其左子树是否为单值二叉树；
3、判定其右子树是否为单值二叉树；
4、综合2、3、得出结果，注意 **符号&&具有短路性质**，即如果已经判定左子树部分不是单值二叉树，右子树部分就不需要判定了。
```
bool isUnivalTree(TreeNode* root) {
	if (!root) return true; //空树
	if (!root->left || !root->right) return true; //叶子
	return helper(root->left, root->val) && helper(root->right, root->val);
}
bool helper(TreeNode *root, int cmp) {
	if (!root) return true; //空树 
	if (root->val != cmp) return false; //根结点不相等
	return helper(root->left, cmp) && helper(root->right, cmp); //判定左子树、右子树是否为单值二叉树
} //遵循先序遍历
```