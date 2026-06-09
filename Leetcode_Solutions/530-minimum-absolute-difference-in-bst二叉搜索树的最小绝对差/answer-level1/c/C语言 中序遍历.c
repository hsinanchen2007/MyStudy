### 解题思路
中序遍历，记录最小差值

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

void midTra(struct TreeNode* root, int *last_val, int *min)
{
	int diff;
	if (root == NULL) {
		return;
	}
	midTra(root->left, last_val, min);
	diff = abs((*last_val) - root->val);
	*min = diff < *min ? diff : *min;
	*last_val = root->val;
	midTra(root->right, last_val, min);
}

int getMinimumDifference(struct TreeNode* root){
	int last_val = INT_MAX;
	int min = INT_MAX;
	midTra(root, &last_val, &min);
	return min;
}
```