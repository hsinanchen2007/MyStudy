![QQ截图20191103223603.png](https://pic.leetcode-cn.com/1b4dd64a08fc0ee631a84a18e3aa4243aa42d174da0089d3e633eb9ee6bdccae-QQ%E6%88%AA%E5%9B%BE20191103223603.png)

```
迭代法
struct TreeNode* searchBST(struct TreeNode* root, int val)
{
	struct TreeNode *cur=root;
	while(cur)
	{
		if(cur->val==val) return cur;
		else if(val>cur->val) cur=cur->right;
		else cur=cur->left;
	}
	return NULL;
 } 
```
```
递归法
struct TreeNode* searchBST(struct TreeNode* root, int val){
	if(!root) return NULL;
	if(root->val==val) return root;
	
	struct TreeNode *res=searchBST(root->left,val);
	if(res) return res;
	
	return searchBST(root->right,val);

}
```
