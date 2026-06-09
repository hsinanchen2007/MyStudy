### 解题思路
注意root的初始化

### 代码

```golang
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
    root := &TreeNode{}
    mid := len(nums) / 2
    root.Val = nums[mid]
    root.Left = sortedArrayToBST(nums[0:mid])
    root.Right = sortedArrayToBST(nums[mid + 1:])
    return root
}
```