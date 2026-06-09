![image.png](https://pic.leetcode-cn.com/d50ba89a3d0195f71df5de58b1a3155b433bf522b55ada33b1151c7f939eef0e-image.png)

```
func isSameTree(p *TreeNode, q *TreeNode) bool {
	//测试空节点
	if p == nil && q == nil {
		return true
	} else if p == nil || q == nil {
		return false
	}

	if p.Val != q.Val {
		return false
	}
	return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
}
```

