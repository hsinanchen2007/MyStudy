

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
    n := len(nums)
    return helper(nums,0,n-1)
}

func helper(nums []int, left,right int)*TreeNode{
    if left > right {
        return nil
    }
    root := new(TreeNode)
    p := (left+right)/2
    root.Val = nums[p]
    root.Left = helper(nums,left,p-1)
    root.Right = helper(nums,p+1,right)
    return root
}
```