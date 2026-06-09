### 解题思路
第一次递归遍历找到最大深度
第二次递归进行求和
![image.png](https://pic.leetcode-cn.com/0f98e45ef56fed1ce29d6b0e6d686d095b9a5e15142f46e8275be7dadb273f26-image.png)

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

void findDeep(struct TreeNode* node, int *deepLevel, int level)
{
	level++;
	if (level > *deepLevel) {
		*deepLevel = level;
	}
	
	if (node->left == NULL && node->right == NULL) {
		return;
	}
	
	if (node->left != NULL) {
		findDeep(node->left, deepLevel, level);
	}
	if (node->right != NULL) {
		findDeep(node->right, deepLevel, level);
	}
}

void sumDeep(struct TreeNode* node, int deepLevel, int level, int *sum) {
	level++;
	if (level == deepLevel) {
		*sum += node->val;
		return;
	}
	if (node->left != NULL) {
		sumDeep(node->left, deepLevel, level, sum);
	}
	if (node->right != NULL) {
		sumDeep(node->right, deepLevel, level, sum);
	}
}

int deepestLeavesSum(struct TreeNode* root){
	int deeplevel = 0;
	int sum = 0;
	findDeep(root, &deeplevel, 0);
	//printf("deeplevel = %d\n", deeplevel);
	sumDeep(root, deeplevel, 0, &sum);
	return sum;
}
```