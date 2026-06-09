![QQ截图20191108153445.png](https://pic.leetcode-cn.com/51dfe73fed3327746b680c514ee822e6d4435e768d132630e38c08d41508a28f-QQ%E6%88%AA%E5%9B%BE20191108153445.png)

```
//辅助函数 
void help(struct TreeNode *root,int sum[],int cur)
{
	/*
		sum[0]为所有数之和 利用数组保证线程安全 
		cur为从根节点到当前节点所表示的二进制的数 
		每次遍历到一个节点将cur左移一位并加上当前节点的值
		并根据其左右孩子有无来进行下一步递归 
	*/
	
	//左移一位并加上当前节点的值 
	cur=cur*2 + root->val;
	
	//不存在左右子树 
	if(!root->left&&!root->right) 
	{
		sum[0] += cur;
		return ;
	}
	//存在右子树 
	else if(!root->left)
	{
		help(root->right,sum,cur);
	}
	//存在左子树 
	else if(!root->right)
	{
		help(root->left,sum,cur);
	}
	//同时存在左子树和右子树 
	else
	{
		help(root->left,sum,cur);
		help(root->right,sum,cur);
	}
	
}

int sumRootToLeaf(struct TreeNode* root){

	int sum[]={0};
	int cur=0;
	help(root,sum,cur);
	return sum[0];
}
```

