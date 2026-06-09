### 解题思路
简单递归

执行用时 :
0 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗 :
5.8 MB
, 在所有 C 提交中击败了
100.00%
的用户

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

void goThroughTree(struct TreeNode* node, int value, int *total)
{
	if (node->left)
		goThroughTree(node->left, value * 10 + node->val, total);
	if (node->right)
		goThroughTree(node->right, value * 10 + node->val, total);
	if (!node->left && !node->right)
		*total += value * 10 + node->val;
}

int sumNumbers(struct TreeNode* root){
	int total = 0;

	if (!root)
		return 0;
	goThroughTree(root, 0, &total);
	return total;
}
```