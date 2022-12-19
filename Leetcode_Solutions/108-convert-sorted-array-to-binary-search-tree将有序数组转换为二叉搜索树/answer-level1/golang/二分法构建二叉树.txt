```
func sortedArrayToBST(nums []int) *TreeNode {
	n := len(nums)
	if n == 0 {
		return nil
	}
	return fillMidNode(nums, 0, n-1)
}

func fillMidNode(nums []int, start, end int) *TreeNode {
	node := &TreeNode{}
	if start > end {
		return nil
	}
	mid := start + (end-start)>>1
	node.Val = nums[mid]
	node.Left = fillMidNode(nums, start, mid-1)
	node.Right = fillMidNode(nums, mid+1, end)
	return node
}
```