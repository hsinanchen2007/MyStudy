# 111. 二叉树的最小深度（C语言 递归）
递归寻找树深度的变形，每次只需要返回左右子树深度的最小值。

注意:
1. 当左子树为空时，返回右子树深度；
2.  当右子树为空时，返回左子树深度。

```
int minDepth(struct TreeNode* root){
	if(root == NULL){
		return 0;
	}

	int left_length = minDepth(root->left) + 1;
	int right_length = minDepth(root->right) + 1;
	
	if( root->left == NULL ){
		return right_length;
	}else if( root->right == NULL ){
		return left_length;
	}else if( left_length >= right_length ){
		return right_length;
	}else{
		return left_length;
	}
}
```
