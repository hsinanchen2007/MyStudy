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
/*
[1,2,3]
[-10,9,20,null,null,15,7]
[-3]
[1,2]
[2,-1]
[1,-2,3]

[5,4,8,11,null,13,4,7,2,null,null,null,1]
*/

#define min(x, y) ((x) > (y) ? (y) : (x))

#define max(x, y) ((x) > (y) ? (x) : (y))

int g_maxSum = -100000000;

int DFS(struct TreeNode *root)
{
	g_maxSum = max(g_maxSum, root->val);

	if (root->left == NULL && root->right == NULL) {
		printf("g_maxSum1 %d \n", g_maxSum);
		return root->val;
	}

	int lSum = 0;
	int rSum = 0;
	if (root->left != NULL) {
		lSum = DFS(root->left);
	}
	if (root->right != NULL) {
		rSum = DFS(root->right);
	}

	int ret0 = root->val;
	int ret1 = root->val + lSum;
	int ret2 = root->val + rSum;
	int ret3 = root->val + lSum + rSum;
	int ret4 = max(ret1, ret2);
	int ret5 = max(ret3, ret4);
	int ret = max(ret5, ret0);;

	g_maxSum = max(g_maxSum, ret);
	printf("g_maxSum2 %d \n", g_maxSum);

	ret = max(ret4, ret0);
	return ret;
}

int maxPathSum(struct TreeNode *root) {
	g_maxSum = -100000000;

	DFS(root);
	return g_maxSum;
}
```