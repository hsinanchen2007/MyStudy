这道题就是中序遍历每一个结点
但我们需要的只是左叶子结点
所以只需要累加左叶子结点的值即可。
```
class Solution {
private:int ans;
public:
	void search(TreeNode* root){
	if(root==NULL) return;
	search(root->left);
	search(root->right);
	if(root->left&&!root->left->left&&root->left->right) ans+=root->left->val;

	return;
	}

    int sumOfLeftLeaves(TreeNode* root) {
		ans=0;
		search(root);
		return ans;
    }
};
```
