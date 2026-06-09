思路：递归中序遍历BST，直到第K个元素为止。

```
执行用时 :12 ms, 在所有 Go 提交中击败了99.30%的用户
内存消耗 :6 MB, 在所有 Go 提交中击败了56.10%的用户
```
```Go []
func kthSmallest(root *TreeNode, k int) int {
	kv := 0
	var findKth func(r *TreeNode)
	findKth = func(r *TreeNode) {
		if r == nil || k == 0 {
			return
		}
		findKth(r.Left)
		k--
		if k == 0 {
			kv = r.Val
			return
		}
		findKth(r.Right)
	}
	findKth(root)
	return kv
}
```
[LeetCodeByGo: 更多LeetCode题库Go语言题解](https://github.com/mrandmrsbenben/LeetCodeByGo)