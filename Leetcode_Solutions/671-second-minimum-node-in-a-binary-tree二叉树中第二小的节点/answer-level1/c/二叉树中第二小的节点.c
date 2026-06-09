
![QQ截图20191031212231.png](https://pic.leetcode-cn.com/b3837e27003c9f022ac149cc8b84019c52b116dc4740f707b5aa7ff81821eb2d-QQ%E6%88%AA%E5%9B%BE20191031212231.png)

```
在左右子树中查找大于根节点值的最小节点
int findMin(struct TreeNode *root,int data)
{
	if(!root) return -1;
	if(root->val > data) return root->val;
	
	int left = findMin(root->left,data);
	int right = findMin(root->right,data);
	
	if(left==-1) return right;
	if(right==-1) return left;
	
	return left > right ? right : left;
	
}

int findSecondMinimumValue(struct TreeNode* root){
	return findMin(root,root->val);
}

```
