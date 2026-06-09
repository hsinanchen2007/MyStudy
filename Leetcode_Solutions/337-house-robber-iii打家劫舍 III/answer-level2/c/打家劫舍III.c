### 解题思路
给每一个结点定义两种状态，0--不偷，1--偷，那么可以自底而上的计算到根节点的最优解
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
#define MAX(a,b) (a>b?a:b)

int *doRob(struct TreeNode* root) {
	int *rob = (int*)malloc(sizeof(int) * 2);
	memset(rob, 0, sizeof(int) * 2);
	if (!root) return rob;
	int* left = doRob(root->left);
	int* right = doRob(root->right);
	rob[0] = MAX(left[0], left[1]) + MAX(right[0] , right[1]);
	rob[1] = root->val + left[0] + right[0];
	return rob;
}
int rob(struct TreeNode* root) {
	int *rob = doRob(root);
	return MAX(rob[0], rob[1]);
}

```