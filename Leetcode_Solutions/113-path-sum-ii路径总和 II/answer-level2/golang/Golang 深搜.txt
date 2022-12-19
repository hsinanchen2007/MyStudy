执行耗时:0 ms,击败了100.00% 的Go用户
内存消耗:4.5 MB,击败了68.79% 的Go用户

```go
func pathSum(root *TreeNode, sum int) [][]int {
	ans := make([][]int, 0)
	path := make([]int, 0)
	helper(root, sum, &ans, path)
	return ans
}

func helper(root *TreeNode, sum int, ans *[][]int, path []int) {
	if root == nil {
		return
	}
	path = append(path, root.Val)
	if root.Left == nil && root.Right == nil && root.Val == sum {
		tmp := make([]int, len(path))
		copy(tmp, path)
		*ans = append(*ans, tmp)
		return
	}
	helper(root.Left, sum-root.Val, ans, path)
	helper(root.Right, sum-root.Val, ans, path)
	path = path[:len(path)-1]  // 回溯，消除上一步造成的影响
}
```