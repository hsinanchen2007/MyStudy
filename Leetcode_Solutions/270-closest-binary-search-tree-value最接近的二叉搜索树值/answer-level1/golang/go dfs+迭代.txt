```
//迭代
func closestValue(root *TreeNode, target float64) int {
	val, closest := root.Val, root.Val
	for root != nil {
		val = root.Val
		if math.Abs(float64(val)-target) < math.Abs(float64(closest)-target) {
			closest = val
		} else {
			closest = closest
		}
		if target < float64(root.Val) {
			root = root.Left
		} else {
			root = root.Right
		}
	}
	return closest
}
//递归

func dfs(root *TreeNode, nums *[]int) {
	if root == nil {
		return
	}
	dfs(root.Left, nums)
	*nums = append(*nums, root.Val)
	dfs(root.Right, nums)
}

func closestValue(root *TreeNode, target float64) int {
	if target > math.MaxFloat64 {
		return 0
	}
	if root.Left == nil && root.Right == nil {
		return root.Val
	}
	nums := []int{}
	dfs(root, &nums)
	val := nums[0]
	for i := 1; i < len(nums); i++ {
		if math.Abs(float64(val)-target) < math.Abs(float64(nums[i])-target) {
			val = val
		} else {
			val = nums[i]
		}
	}
	return val
}
```
