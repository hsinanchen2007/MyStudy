### 解题思路
递归遍历

![image.png](https://pic.leetcode-cn.com/7c1d280c4fbc05ee263fa862d4e36e61168e6e68d573055fd51e38a6ee01dd9d-image.png)


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

void trans(struct TreeNode* root, int cur, int *sum)
{
	if (root == NULL) {
		return;
	}
	cur = cur * 2 + root->val;
	if (root->left == NULL && root->right == NULL) {
		*sum = (*sum + cur) % ((int)pow(10,9) + 7);
		return;
	}
	trans(root->left, cur, sum);
	trans(root->right, cur, sum);
	return;
}
int sumRootToLeaf(struct TreeNode* root){
	int sum = 0;
	trans(root, 0, &sum);
	return sum;
}
```