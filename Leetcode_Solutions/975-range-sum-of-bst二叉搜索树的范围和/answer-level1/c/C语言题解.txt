int rangeSumBST(struct TreeNode* root, int L, int R){
	if (root == NULL) {
		return 0;
	}

	int ret = 0;
	if (root->val >= L && root->val <= R) {
		ret += root->val;
		ret += rangeSumBST(root->left, L, R);
		ret += rangeSumBST(root->right, L, R);
	} else if (root->val < L) {
		ret += rangeSumBST(root->right, L, R);
	} else {
		ret += rangeSumBST(root->right, L, R);
	}
	return ret;

}