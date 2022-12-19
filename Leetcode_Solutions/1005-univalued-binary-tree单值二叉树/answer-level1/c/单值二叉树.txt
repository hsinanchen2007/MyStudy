```

//对树进行先序遍历
//遇到与根节点值不相等的节点返回false
//如果遍历完则返回true 
bool help(struct TreeNode *root,int val)
{
	if(!root) return true;
	
	if(root->val != val) return false;
	
	return help(root->left,val) &&help(root->right,val);
}

bool isUnivalTree(struct TreeNode* root){
	
	return help(root,root->val) ;
}
```
