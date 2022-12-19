```
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	queue := make([]*TreeNode, 0)
	queue = append(queue, root)
	queue = append(queue, root)

	for {
		if len(queue) >= 2 {
			left := queue[0]
			right := queue[1]
			queue = queue[2:]
			if left != nil && right != nil {
				if left.Val == right.Val {
					queue = append(queue, left.Left)
					queue = append(queue, right.Right)
					queue = append(queue, left.Right)
					queue = append(queue, right.Left)
					continue
				} else {
					return false
				}
			} else if left == nil && right == nil {
				continue
			} else {
				return false
			}
			continue
		}
		break
	}
	return true
}
```
