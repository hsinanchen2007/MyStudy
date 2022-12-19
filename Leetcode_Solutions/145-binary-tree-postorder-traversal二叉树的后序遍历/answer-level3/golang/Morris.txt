时间复杂度：O(n)
空间复杂度：O(1)
```
//morris遍历：
// 执行用时 : 0 ms, 在所有 Go 提交中击败了100.00%的用户
// 内存消耗 : 2 MB, 在所有 Go 提交中击败了98.67%的用户
func postorderTraversal(root *TreeNode) []int {
	var res []int
	var mostRight *TreeNode
	cur := root
	for cur != nil {
		mostRight = cur.Left
		if mostRight != nil {
			for mostRight.Right != nil && mostRight.Right != cur {
				mostRight = mostRight.Right
			}
			if mostRight.Right == nil {
				mostRight.Right = cur
				cur = cur.Left
				continue
			} else { // 把所有的节点的打印放在第二次来到该节点的时候，逆序打印左子树的右边界
				mostRight.Right = nil
				res = append(res, printRightBorder(cur.Left)...)
			}
		}
		cur = cur.Right
	}
	res = append(res, printRightBorder(root)...)
	return res
}

func printRightBorder(node *TreeNode) []int {
	var res []int
	tail := reverse(node)
	cur := tail
	for cur != nil {
		res = append(res, cur.Val)
		cur = cur.Right
	}
	reverse(tail)
	return res
}

func reverse(node *TreeNode) *TreeNode {
	var pre, next *TreeNode
	for node != nil {
		next = node.Right
		node.Right = pre
		pre = node
		node = next
	}
	return pre
}

```
