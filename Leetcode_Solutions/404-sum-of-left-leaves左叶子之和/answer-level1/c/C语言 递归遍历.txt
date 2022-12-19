### 解题思路
递归遍历

![image.png](https://pic.leetcode-cn.com/0d77d48a3d854cbaf3975c1ab78dd4f29437f8d78d68a86bac07b4e01ac5fa23-image.png)


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

void trans(struct TreeNode* root, bool isLeft, int *sum)
{
	if (root == NULL) {
		return;
	}
	if (root->left == NULL && root->right == NULL) {
		if (isLeft == true) {
			*sum = *sum + root->val;
		}
		return;
	}
	trans(root->left, true, sum);
	trans(root->right, false, sum);
	return;
}

int sumOfLeftLeaves(struct TreeNode* root){
	int sum = 0;
	trans(root, false, &sum);
	return sum;
}
```