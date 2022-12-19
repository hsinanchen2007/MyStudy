```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void iBST(struct TreeNode* root, struct TreeNode** newRoot, struct TreeNode** head)
{
	struct TreeNode *leaf = NULL;
	if (root == NULL) {
		return;
	}
	iBST(root->left, newRoot, head);
	leaf = (struct TreeNode*)calloc(sizeof(struct TreeNode), 1);
	if (leaf == NULL) {
		return;
	}
	leaf->val = root->val;
	if (*newRoot == NULL) {
		*head = leaf;
	} else {
		(*newRoot)->right = leaf;
	}
	*newRoot = leaf;
	
	iBST(root->right, newRoot, head);
	return;
}

struct TreeNode* increasingBST(struct TreeNode* root){
	struct TreeNode* head = NULL;
	struct TreeNode* newRoot = NULL;
	iBST(root, &newRoot, &head);
	return head;
}
```
