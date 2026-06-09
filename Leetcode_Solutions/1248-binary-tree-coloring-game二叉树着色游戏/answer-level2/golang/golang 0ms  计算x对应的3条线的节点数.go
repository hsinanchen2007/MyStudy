只有拿到和x相邻的节点，才能保证我所拿到的节点数最多。

与x相邻的节点可能有3个， 左节点的树, 右节点的树， 父节点对应的其他节点。

那么我们只需要找到x对应的节点。计算左右节点数，再根据n，计算其他节点树。其中的最大值就是我们能拿到的最大数。


```
func btreeGameWinningMove(root *TreeNode, n int, x int) bool {
	arrs := make([]int, 3)
	arrs[0], arrs[1], _ = find(root, x)
	arrs[2] = n - arrs[0] - arrs[1] - 1
	sort.Ints(arrs)
	return arrs[2] > arrs[0] + arrs[1] + 1
}

func find(root *TreeNode, x int) (left, right int, isFind bool) {
	if root == nil {
		return 0, 0, false
	}
	if root.Val == x {
		return rootCount(root.Left), rootCount(root.Right), true

	}
	left, right, isFind = find(root.Left, x)
	if isFind {
		return
	}
	left, right, isFind = find(root.Right, x)
	return
}

// 计算root这个树的节点数
func rootCount(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return 1 + rootCount(root.Left) + rootCount(root.Right)
}

```
