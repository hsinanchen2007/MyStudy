递归法，扫描同层结果插入法需注意
执行用时 : 0 ms, 在所有 golang 提交中击败了100.00%的用户

```go
func zigzagLevelOrder(root *TreeNode) [][]int {
	var result [][]int
	search := func(level int, root *TreeNode) {} // 递归预定义
	search = func(level int, root *TreeNode) {   // 递归函数体
		if root == nil {
			return
		}
		if level+1 > len(result) { // 扩展结果集合大小
			result = append(result, []int{})
		}
		search(level+1, root.Right) // 递归搜索
		search(level+1, root.Left)
		if (level % 2) == 1 { // 左右扫描不同层
			result[level] = append(result[level], root.Val)
		} else {
			result[level] = append([]int{root.Val}, result[level]...)
		}
	}
	search(0, root)
	return result
}
```
