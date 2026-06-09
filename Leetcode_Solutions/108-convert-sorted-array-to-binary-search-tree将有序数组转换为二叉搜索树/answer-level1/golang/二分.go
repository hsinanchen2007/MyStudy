二分创建节点，左边的始终是左节点，右边的始终是右节点
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedArrayToBST(nums []int) *TreeNode {
    if len(nums) == 0 {
        return nil
    }
	left := 0
	right := len(nums)-1
	head := halfSearch(left,right,nums)
	return head

}

func halfSearch(left, right int, nums []int) *TreeNode {
	mid := left + (right-left)/2
	midNode := &TreeNode{Val:nums[mid]}
	if mid == left {
		midNode.Left = nil
	}else if mid-1 == left {
		midNode.Left = &TreeNode{Val:nums[left]}
	}else  {
		midNode.Left = halfSearch(left, mid-1, nums)
	}

	if mid == right {
		midNode.Right = nil
	}else if mid+1 == right {
		midNode.Right = &TreeNode{Val:nums[right]}
	}else {
		midNode.Right = halfSearch(mid+1, right, nums)
	}
	return midNode
}
```
