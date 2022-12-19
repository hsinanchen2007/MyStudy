### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int gMaxLeave = 0;
int gSum = 0;

int DFS(struct TreeNode *root, int leave)
{
	if (root == NULL) {
		return leave;
	}

	if (root->left == NULL && root->right == NULL) {
		if (leave > gMaxLeave) {
			gMaxLeave = leave;
			gSum = root->val;
		} else if (leave == gMaxLeave) {
			gSum = gSum + root->val;
		}
	}

	(void)DFS(root->left, leave + 1);
	(void)DFS(root->right, leave + 1);

	return leave;
}

int deepestLeavesSum(struct TreeNode* root){
	gMaxLeave = 0;
	gSum = 0;

	(void)DFS(root, 0);

	return gSum;
}
```