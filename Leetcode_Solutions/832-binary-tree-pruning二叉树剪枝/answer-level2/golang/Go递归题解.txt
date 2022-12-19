思路：对左右子树分别递归判断并剪枝。

```
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2.7 MB, 在所有 Go 提交中击败了27.27%的用户
```
```Go []
func pruneTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	if notContainsOne(root.Left) {
		root.Left = nil
	} else {
		pruneTree(root.Left)
	}
	if notContainsOne(root.Right) {
		root.Right = nil
	} else {
		pruneTree(root.Right)
	}
	return root
}

func notContainsOne(root *TreeNode) bool {
	if root == nil {
		return true
	} else if root.Val == 1 {
		return false
	} else if root.Left == nil && root.Right == nil {
		return root.Val == 0
	}
	return notContainsOne(root.Left) && notContainsOne(root.Right)
}

```
更多LeetCode题库Go语言题解参考[LeetCodeByGo](https://github.com/mrandmrsbenben/LeetCodeByGo)