# 自顶向下

```golang
func isBalanced(node *TreeNode) bool {
	return node == nil || isBalanced(node.Left) &&
		math.Abs(height(node.Left)-height(node.Right)) < 2 && //两边最大深度差  大于2
		isBalanced(node.Right)
}

//计算节点最大深度
func height(node *TreeNode) float64 {
	if node == nil {
		return 0
	}
	return math.Max(height(node.Left), height(node.Right)) + 1
}

// 计算深度->对比深度
```




# 自底向上

**模板**：`后序遍历` 左右根


```golang
func isBalanced(node *TreeNode) bool {
	return find(node) != -1
}

func find(node *TreeNode) float64 {
	if node == nil {
		return 0
	}

	l := find(node.Left) //!左节点
	if l == -1 { //剪枝，不平衡时直接返回，
		return -1
	}

	r := find(node.Right)//!右节点
	if r == -1 { //剪枝，不平衡时直接返回
		return -1
	}

	if math.Abs(l-r) > 1 { //剪枝，不平衡时直接返回
		return -1
	}

	return math.Max(l, r) + 1 //计算深度 !根节点
}
```

[Go版本的一题多解 Github](https://github.com/temporaries/leetcode)
