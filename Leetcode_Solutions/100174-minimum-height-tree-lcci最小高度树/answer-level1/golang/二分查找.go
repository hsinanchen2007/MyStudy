### 解题思路
由于是有序整数，那么在找到根节点后，我们可以将数组一分为二，其左侧必然是左子树，右侧必然是右子树。

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
    ln := len(nums)
    if ln == 0{
        return nil
    }
    mid := ln/2
    t := new(TreeNode)
    t.Val = nums[mid]
    t.Left = sortedArrayToBST(nums[0:mid])
    t.Right = sortedArrayToBST(nums[mid+1:])
    return t
}
```