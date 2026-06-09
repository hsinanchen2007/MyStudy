```

func rightSideView(root *TreeNode) []int {
	nums := make([]int, 0)
	helperRightSideView(root, &nums, 0)
	return nums
}

func helperRightSideView(root *TreeNode, nums *[]int, sum int) {
	if root == nil {
		return
	}
	if sum >= len(*nums) {
		*nums = append(*nums, 0)
	}
	(*nums)[sum] = root.Val
	if root.Left != nil {
		helperRightSideView(root.Left, nums, sum+1)
	}
	if root.Right != nil {
		helperRightSideView(root.Right, nums, sum+1)
	}
}
```
