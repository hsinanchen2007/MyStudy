# dfs
只要左树 右树 有 p q,就必定是答案拉

```golang
 func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
  	if root == nil || root == p || root == q {
		return root
	}
	l := lowestCommonAncestor(root.Left, p, q)
	r := lowestCommonAncestor(root.Right, p, q)
	if l == nil {
		return r
	}
	if r == nil {
		return l
	}
	return root
}
```

[Go版本 Github](https://github.com/temporaries/leetcode)
