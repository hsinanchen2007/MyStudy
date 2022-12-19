思路如下：
  本题只有两种情况，一种是返回p或者q，另一种情况是返回除p、q以外的其它某一节点。深度优先遍历该二叉树，如果存在一个节点，它的左右子树中各包含一个等于p、q的指针，那么指向该结点的指针就有可能是结果。如果没有任何结点的左子树和右子树各包含一个和p、q相等的指针，那结果就是p或者q。

```
vector<TreeNode*> ans;
TreeNode* x;
TreeNode* y;
int flag=0;
int getans(TreeNode* root){
	if(ans.size()>0)return 0;
	if(root==nullptr)return 0;
	if(root==x){
		if(flag==0)flag=1;
		return 1;}
	if(root==y){
	    if(flag==0)flag=2;
     	return 1;
	}
	int a=0+getans(root->left);
	if(ans.size()>0)return 0;
	int b=0+getans(root->right);
	if(ans.size()>0)return 0;
	if(a>0&&b>0)ans.push_back(root);
	else if(a==0&&b==0)return 0;
	return 1;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)return root;
		x = p;
		y = q;
		getans(root);
		if(ans.size()>0)return ans[0];
		if(flag==1)return x;
		return y;
}
```
