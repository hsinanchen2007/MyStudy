### 解题思路
基础树操作

### 代码

```c


struct TreeNode* deleteNode(struct TreeNode* root, int key){
	struct TreeNode* tmp, *pre = NULL;

    if (root == NULL) {
		return NULL;
	}
	if (root->val != key) {
		root->left = deleteNode(root->left, key);
		root->right = deleteNode(root->right, key);
		return root;
	}

	if (root->right == NULL) {
		return root->left;
	}

	if (root->left == NULL) {
		return root->right;
	}

	tmp = root->right;
	pre = root;
	while(tmp->left) {
		pre = tmp;
		tmp = tmp->left;
	}
	root->val = tmp->val;
	if (pre == root)
        root->right = tmp->right;
    else
		pre->left = tmp->right;
	
	
	return root;
}
```