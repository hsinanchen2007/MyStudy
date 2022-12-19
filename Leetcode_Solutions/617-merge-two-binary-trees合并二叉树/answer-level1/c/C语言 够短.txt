执行结果：通过显示详情
执行用时 :32 ms, 在所有 c 提交中击败了90.70%的用户
内存消耗 :16.2 MB, 在所有 c 提交中击败了83.02%的用户
```
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2)
{
	if (!t1){return t2;}
	if (!t2){return t1;}
	t1->val +=t2->val;
	t1->left=mergeTrees(t1->left,t2->left);
	t1->right=mergeTrees(t1->right,t2->right);
	return t1;
}

```
