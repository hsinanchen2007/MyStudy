# 104. 二叉树的最大深度（C语言 递归）
1. 想知道二叉树的最大深度。就需要先序遍历的方式找到每一个叶子节点，从该叶子节点一步一步回溯到根节点。
2. 叶子节点可以看为左右子树节点都为NULL的节点。
3. 我们从不为NULL的节点递归返回0，直到根节点每个节点都加1。
4. 对于每个节点我们会得到两个深度值，分别是左子树/右子树深度，我们返回最大的深度，直到根节点。


![image.png](https://pic.leetcode-cn.com/35982c6c1bbc543417129de386d7ab63f3f50f345912b48cf880b973f1bff48f-image.png)

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
	if(root == NULL){
		return 0;
	}

	int left_length = maxDepth(root->left) + 1;
	int right_length = maxDepth(root->right) + 1;
	
	if( left_length >= right_length){
		return left_length;
	}else{
		return right_length;
	}
}

```

