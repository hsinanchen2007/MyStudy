  第一次DFS将每个节点的值修改为将指向该点的指针删除后以该点为根节点的二叉树的所有值的总和，显然，叶子节点的值不变。本次DFS结束后，根节点的值赋给变量sum。
  第二次DFS暴力搜索所有情况，每遍历到一个点，计算（sum-root->val）*root->val，并与max比较，比max大则更新max。
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   long long  max=0,sum;

int getvalue(TreeNode* root){
	if(root==nullptr)return 0;
	long long  l=getvalue(root->left);
	long long r=getvalue(root->right);
	root->val=l+r+root->val;
	return root->val;
}

void dfs(TreeNode* root){
	if(root==nullptr)return;
	long long v=root->val;
	if(v*(sum-v)>max)max=v*(sum-v);
	dfs(root->left);
	dfs(root->right);
}

int maxProduct(TreeNode* root) {
    getvalue(root);
	sum=root->val;
	dfs(root);
	return max%1000000007;
}
};
```
