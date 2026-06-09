# 101. 对称二叉树（C语言 递归）
 采用递归方式解决该题目。
 1. 由题目可知我们判断一个二叉树是是否对称，那么我们就需要从树中每个最左边节点与最右边节点开始比对，再用次左边节点比对次右边节点以此类推。

 	如图所示 节点中 1 与 1 比较 ， 2 于 2 比较 ，3 与 3比较。

    ![image.png](https://pic.leetcode-cn.com/2a31ed87c75c4b0200487afa1703dae1e63277cb23995163f2ef19f901bbc1c8-image.png)

2. 想要找到一棵树中左边的节点，很容易只需要使用后序遍历的方式。
 可以推出找一棵树中右边的节点，可以将后序遍历中遍历左右节点位置互调，先遍历右节点，再遍历左节点。

3.  这样我们的递归中可以传入当前的左右节点，再找左右节点中的左右节点。
 只有子树中左右节点值都对应（也可以都为空），且该左右点值也对应才返回true，否则返回false。

```

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool find_left_right( struct TreeNode* left , struct TreeNode* right ){
	if( left == NULL && right == NULL ){
		return true;
	}else if( (left != NULL && right == NULL) || (left == NULL && right != NULL ) ){
		return false;
	}
	
	bool find_outside  = find_left_right(left->left,right->right);
	bool find_inside = find_left_right(left->right,right->left);
	
	if( find_outside && find_inside && (left->val == right->val) ){
		return true;
	}else{
		return false;
	}
}
bool isSymmetric(struct TreeNode* root){
	if( root == NULL ){
		return true;
	}
	return find_left_right(root->left,root->right);
}
```




