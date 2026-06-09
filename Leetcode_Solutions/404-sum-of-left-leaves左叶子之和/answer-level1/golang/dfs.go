### 思路
什么遍历都可以，处理一下左节点就完事

### dfs
```golang
var res int

func sumOfLeftLeaves(root *TreeNode) int {
	res = 0
	dfs(root)
	return res
}

func dfs(root *TreeNode) {
	if root == nil {
		return
	}

	if root.Left != nil && root.Left.Left == nil && root.Left.Right == nil {
		res += root.Left.Val
	}
	dfs(root.Left)
	dfs(root.Right)
}
```

[Go版本 Github](https://github.com/temporaries/leetcode)
[对应模板 Github](https://github.com/temporaries/leetcode/blob/master/templates/tree)