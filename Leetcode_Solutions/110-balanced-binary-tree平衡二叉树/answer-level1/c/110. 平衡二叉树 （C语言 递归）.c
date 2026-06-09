# 110. 平衡二叉树 （C语言 递归）
我们需要找到每个树左右子树的深度，在判断子树深度差是否超过1。
由于计算深度时包括当前节点，即左右子树深度+1
所以判断错误后要返回-2，+1后为-1.

```
int findBalanced(struct TreeNode* root){
	if( root == NULL ){
		return 0;
	}
	
	int left_length  = findBalanced(root->left) + 1;
	int right_length = findBalanced(root->right) + 1;
	
	if( left_length == -1 || right_length == -1 || left_length-right_length>1 || left_length-right_length<-1){
		return -2;
	}else if( left_length >= right_length ){
		return left_length;
	}else{
		return right_length;
	}
}

bool isBalanced(struct TreeNode* root){
	if( findBalanced(root) < 0 ){
		return false;
	}else{
		return true;
	}
}
```
