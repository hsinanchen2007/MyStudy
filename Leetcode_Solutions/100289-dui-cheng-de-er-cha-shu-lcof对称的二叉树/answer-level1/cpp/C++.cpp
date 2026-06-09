解题思路:getans中的root1和root2所指的结点对称，对于每一次递归，必须满足:
1 root1->val等于root2->val或root1和root2都为空
2 因为root1和root2所指节点对称，所以root1左孩子等于root2右孩子且root2的左孩子等于root1的右孩子(都为空也算相等)
```
bool getans(TreeNode* root1,TreeNode* root2){
	if(root1==nullptr&&root2==nullptr)return true;
	if(root1==nullptr||root2==nullptr)return false;
	if(root1->val!=root2->val)return false;
	return getans(root1->left,root2->right)&&getans(root1->right,root2->left);
}

bool isSymmetric(TreeNode* root) {
    if(root==nullptr)return true;
	return getans(root->left,root->right);
}
```
