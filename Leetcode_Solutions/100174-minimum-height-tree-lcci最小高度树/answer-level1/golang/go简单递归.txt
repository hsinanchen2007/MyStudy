```
func sortedArrayToBST(nums []int) *TreeNode {
    return helpTool(nums)
}
func helpTool(nums []int) *TreeNode{
    if len(nums)==0{
        return nil
    }else{
        root := new(TreeNode)
        root.Val = nums[len(nums)/2]
        root.Left = helpTool(nums[0:(len(nums)/2)])
        root.Right = helpTool(nums[(len(nums)/2)+1:])
        return root
    }
}
```
