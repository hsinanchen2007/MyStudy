递归遍历各节点左右子树的最大深度和值。为提高速度，可将最大深度*2仍然小于和值的叶子节点跳过不遍历。

```Go []
func diameterOfBinaryTree(root *TreeNode) int {
	if root == nil {
		return 0
	}
	lmax := maxDepth(root.Left)
	rmax := maxDepth(root.Right)
	max := lmax + rmax
	var ld, rd int
	if lmax*2 > max {
		ld = diameterOfBinaryTree(root.Left)
	}
	if rmax*2 > max {
		rd = diameterOfBinaryTree(root.Right)
	}
	if ld > max || rd > max {
		if ld > rd {
			return ld
		}
		return rd
	}
	return max
}

func maxDepth(t *TreeNode) int {
	if t == nil {
		return 0
	}
	depth := 1
	leftD := maxDepth(t.Left)
	rightD := maxDepth(t.Right)
	if leftD > rightD {
		depth = depth + leftD
	} else {
		depth = depth + rightD
	}
	return depth
}