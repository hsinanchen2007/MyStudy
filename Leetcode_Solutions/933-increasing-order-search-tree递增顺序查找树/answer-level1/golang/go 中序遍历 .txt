```
func increasingBST(root *TreeNode) *TreeNode {
	var nums = make([]int, 0)
	dfsincreasingBST(root, &nums)
	ans := &TreeNode{
		Val:   nums[0],
		Right: nil,
		Left:  nil,
	}
	tmp := ans
	for _, v := range nums[1:] {
		next := &TreeNode{
			Val:   v,
			Right: nil,
			Left:  nil,
		}
		tmp.Right = next
		tmp = next
	}
	return ans
}

func dfsincreasingBST(root *TreeNode, nums *[]int) {
	if root == nil {
		return
	}
	dfsincreasingBST(root.Left, nums)
	*nums = append(*nums, root.Val)
	dfsincreasingBST(root.Right, nums)
}
```
