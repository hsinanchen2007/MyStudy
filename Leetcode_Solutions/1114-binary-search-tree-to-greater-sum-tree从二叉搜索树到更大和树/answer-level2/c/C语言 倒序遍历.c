### 解题思路
这道题感觉没有中等难度，二叉树倒序遍历即可

![image.png](https://pic.leetcode-cn.com/32dc8c090a51d279c64729d20aab5dcd118cd4b91719f87a30889315474d71c6-image.png)

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

void process(struct TreeNode* node, int *sum)
{
	if (node == NULL) {
		return;
	}
	if (node->right != NULL) {
		process(node->right, sum);
	}
	*sum += node->val;
	node->val = *sum;
	if (node->left != NULL) {
		process(node->left, sum);
	}
}
struct TreeNode* bstToGst(struct TreeNode* root){
	int sum = 0;
	process(root, &sum);
	return root;
}
```