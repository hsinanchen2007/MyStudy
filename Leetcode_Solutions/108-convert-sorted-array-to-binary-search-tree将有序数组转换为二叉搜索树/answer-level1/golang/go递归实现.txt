```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
//  递归
func sortedArrayToBST(nums []int) *TreeNode {
    if len(nums) == 0{
        return nil
    }
    // 由于是排序好的数组，中位数做根节点，中位数左边的在左子树，右边的为右子树
    mid := len(nums) / 2
    var root *TreeNode = &TreeNode{}
    root.Val = nums[mid]
    root.Left = sortedArrayToBST(nums[:mid])
    root.Right = sortedArrayToBST(nums[mid+1:])
    return root
}
```
