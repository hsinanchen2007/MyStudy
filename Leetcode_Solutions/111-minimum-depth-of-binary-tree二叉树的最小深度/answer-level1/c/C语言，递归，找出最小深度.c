### 解题思路
1.节点为空，返回0
2.节点只有左子树（右子树），向上返回其1+左子树（右子树）的高度
3.节点无左右子树，向上返回1
4.节点有左右子树，向上返回的便是1+左右子树中高度较小的那颗的高度
### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root) {
	if(root == NULL)
		return 0;
	int left = minDepth(root->left);
	int right = minDepth(root->right);
	if (left == 0 && right != 0) //该节点只有右孩子，深度加上其右子树的高度
		return 1 + right;
	if (left != 0 && right == 0) //只有左孩子
		return 1 + left;
	else	//左右孩子都有的话，深度增值为左右子树中较小的哪一个
			//都没有的话，加0
		return 1 + (left > right ? right : left);
}


```