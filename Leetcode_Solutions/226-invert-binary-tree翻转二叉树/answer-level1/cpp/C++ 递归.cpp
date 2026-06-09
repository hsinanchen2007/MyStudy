
# 递归
```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        else{
            TreeNode* r=root->right;
            TreeNode* l=root->left;/*开个变量保存节点*/
            root->left=invertTree(r);
            root->right=invertTree(l);
        }
        return root;
    }
};
```
# 错误的示范
```
TreeNode* invertTree(TreeNode* root) {
	if (root == NULL) return NULL;
		else {
			root->left = invertTree(root->right);/*这里翻转了之后，由于root->left变了，导致下面的invertTree(root->left)也受到影响，因此要像上面开个变量保存下来。
			root->right = invertTree(root->left);
		}
		return root;
}
```