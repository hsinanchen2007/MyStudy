### 解题思路
  这时用了leetcode上的官方题解做的，就是官方题解所说的模拟镜像的方法。

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

bool isMirror(struct TreeNode* t1,struct TreeNode* t2){
    if (t1 == NULL&&t2 == NULL)
		return true;
	if (t1 == NULL || t2==NULL)
		return false;
	return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}
bool isSymmetric(struct TreeNode* root){
	return isMirror(root,root);
}
```