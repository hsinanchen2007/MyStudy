思路：递归遍历二叉树，每个深度保存最左边的叶子值，直到遍历到下一深度。
```
执行用时 :12 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :5.4 MB, 在所有 Go 提交中击败了100.00%的用户
```
```Go []
func findBottomLeftValue(root *TreeNode) int {
	var blv int
	bd := 0
	var getLeftValue func(r *TreeNode, depth int)
	getLeftValue = func(r *TreeNode, depth int) {
		if r == nil {
			return
		}
		getLeftValue(r.Left, depth+1)
		if depth > bd {
			bd = depth
			blv = r.Val
		}
		getLeftValue(r.Right, depth+1)
	}
	getLeftValue(root, 1)
	return blv
}
```
[LeetCodeByGo: 更多LeetCode题库Go语言题解](https://github.com/mrandmrsbenben/LeetCodeByGo)