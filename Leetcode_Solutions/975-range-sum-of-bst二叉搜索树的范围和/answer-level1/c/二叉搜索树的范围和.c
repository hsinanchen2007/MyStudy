![QQ截图20191106221659.png](https://pic.leetcode-cn.com/c9237d42462bde0ed30dff0967b9b54b574890037307424aabc6669005a9d4de-QQ%E6%88%AA%E5%9B%BE20191106221659.png)


```
int rangeSumBST(struct TreeNode* root, int L, int R){
	
	//递归 结束条件 
	if(!root) return 0;
	
	int lef=0,rig=0,cur=0;
	
	//当前节点值 > 最大值 
	//到左子树中查找 
	if(root->val>R) lef=rangeSumBST(root->left,L,R);
	
	//当前节点值 < 最小值 
	//到右子树中查找 
	else if(root->val<L) rig=rangeSumBST(root->right,L,R);
	
	//当前节点值 在最大值和最小值之间 
	else 
	{
		lef=rangeSumBST(root->left,L,R);
		rig=rangeSumBST(root->right,L,R);
		cur=root->val;
	}
	
	return cur+lef+rig;
}

```
