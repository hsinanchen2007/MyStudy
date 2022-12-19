### 解题思路
用栈应该会更好一些，不过对于C来说要手撸栈。

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


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if ((!q&&p) || (!p&&q))
		return false;
	else if (!q && !p)
		return true;
	else if (p->val != q->val)
		return false;
	else if (p->val == q->val)
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    return true;

}
```