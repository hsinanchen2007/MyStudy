```
func minDiffInBST(root *TreeNode) int {
	var (
		nums = make([]int, 0)
		ans  = math.MaxInt32
	)
	dfsMinDiff(root, &nums)
	sort.Ints(nums)
	for i := 0; i < len(nums)-1; i++ {
		ans = int(math.Min(float64(ans), float64(nums[i+1]-nums[i])))
	}
	return ans
}

func dfsMinDiff(root *TreeNode, nums *[]int) {
	if root == nil {
		return
	}
	*nums = append(*nums, root.Val)
	dfsMinDiff(root.Left, nums)
	dfsMinDiff(root.Right, nums)
}
```
