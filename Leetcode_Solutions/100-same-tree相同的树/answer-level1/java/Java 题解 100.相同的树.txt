## 思路
之前做了965单值二叉树，所以想到可以借鉴一下，用递归实现

## 实现
```
	public boolean isSameTree(TreeNode p, TreeNode q) {
		boolean left_correct = p == null && q == null || p != null && q != null && p.val == q.val && isSameTree(p.left, q.left);
		boolean right_correct = p == null && q == null || p != null && q != null && p.val == q.val && isSameTree(p.right, q.right);
		return left_correct && right_correct;
	}
```