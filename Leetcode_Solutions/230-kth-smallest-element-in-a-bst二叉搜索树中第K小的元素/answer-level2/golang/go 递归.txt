```
func kthSmallest(root *TreeNode, k int) int {
	nums := make([]int, 0)
	helperKthSmallest(root, &nums)
	return nums[k-1]
}

func helperKthSmallest(root *TreeNode, nums *[]int) {
	if root == nil {
		return
	}
	helperKthSmallest(root.Left, nums)
	*nums = append(*nums, root.Val)
	helperKthSmallest(root.Right, nums)
}
```
