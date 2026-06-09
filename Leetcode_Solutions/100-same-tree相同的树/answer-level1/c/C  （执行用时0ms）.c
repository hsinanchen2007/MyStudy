### 解题思路
此处撰写解题思路
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.9 MB, 在所有 C 提交中击败了79.85%的用户
我用的是后序遍历，关于这道题，写递归结束标志的时候一定是两个中至少有一个出现NULL，以此作为依据来进行推理，b通过模仿机器来进行书写。
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
	if (p == NULL&&q == NULL)
		return true;
	else if (p == NULL&&q != NULL || p != NULL&&q == NULL)
		return false;
	if (!isSameTree(p->left, q->left))
		return false;
	if (!isSameTree(p->right, q->right))
		return false;
	if (p->val == q->val)
		return true;
	else
		return false;
}
```